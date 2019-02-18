#include <string>
#include <iostream>

using std::string;

namespace case_1 {
    class User {
        string name;
        string surname;
        uint64_t id;

    public:
        User(string name, string surname, uint64_t id) :
            name(std::move(name)),
            surname(std::move(surname)),
            id(id) {}

    };

    void main() {
        User user1("John", "Doe", 10);

        string s = "John";
        User user(s, "Doe", 10);
    }
}

namespace case_2 {

    struct User {
        string name;

        void set_name(string const& name) {
            this->name = name;
        }

        void set_name(string&& name) {
            this->name = std::move(name);
        }

//        void set_name(string name) {
//            this->name = std::move(name);
//        }

    };

    struct Room {
        User boss;

        void set_boss_name(string s) {
            boss.set_name(std::move(s));
        }
    };

    struct Organisation {
        Room room;

        void set_boss_name(string s) {
            room.set_boss_name(std::move(s));
        }
    };

    void foo(Organisation& o) {
        o.set_boss_name("John");
    }
}

namespace case_3 {
    struct my_string {
        string inner;

        explicit my_string(string inner) : inner(std::move(inner)) {}

        my_string(my_string const& other): inner(other.inner) {
            std::cout << "Copied!" << std::endl;
        };

        my_string(my_string&& other) : inner(std::move(other.inner)) {
            std::cout << "Moved!" << std::endl;
        };

        my_string& operator+=(my_string const& other) {
            inner += other.inner;
            return *this;
        }
    };

    my_string operator+(my_string l, my_string const& r) {
        return l += r;
    }

    void main() {
        my_string s1{"1, 2, 3"};
        my_string s2{"1, 2, 3"};

        my_string s3 = s1 + s2;
    }
}

namespace case_4 {
    template<typename T>
    struct Container {
        void insert(T&& t) {
        }
    };

    void foo() {
        Container<string> cont;
        cont.insert("hello");

        string s = "hi";
        cont.insert(s);
    }
}


int main() {
    case_3::main();
}