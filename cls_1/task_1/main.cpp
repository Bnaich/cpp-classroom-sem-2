#include <iostream>
#include "range.h"

#include <string>
#include <vector>
#include <list>
#include <forward_list>

#include <cassert>
#include <unordered_map>
#include <map>

using namespace std;

void test1() {
    {
        vector<int> v = {1, 2, 3};

        int sum = 0;
        for (auto i : make_range(v.begin(), v.end())) {
            sum += i;
        }

        assert(sum == 6);
    }

    {
        vector<int> v;
        int sum = 0;

        for (auto i : make_range(v.begin(), v.end())) {
            sum += i;
        }

        assert(sum == 0);
    }

    {
        vector<string> v = {"1", "2", "3"};
        string sum;

        for (auto& i : make_range(v.begin(), v.end()).reversed()) {
            sum += i;
        }

        assert(sum == "321");
    }
}

void test2() {
    {
        forward_list<int> list = {1, 2, 3};
        int sum = 0;

        for (auto i : make_range(list.begin(), list.end())) {
            sum += i;
        }

        assert(sum == 6);
    }

    {
        forward_list<int> list = {1, 2, 3};
        int sum = 0;

// should not compile!
//        for (auto i : make_range(list.begin(), list.end()).reversed()) {
//            sum += i;
//        }

        assert(sum == 0);
    }
}

void test3() {
    {
        multimap<int, string> map = {{1, "Hello"}, {1, "Hi"},
                                     {2, "Bye"}, {2, "Goodbye"}};

        string sum;
        for (auto& i: make_range(map.equal_range(2)).reversed()) {
            sum += i.second;
        }

        assert(sum == "Hi Hello");
    }
}

int main() {
    test1();
    test2();
    test3();
}