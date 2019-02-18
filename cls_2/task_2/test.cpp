#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cassert>

#include "sort.hpp"

using std::vector;
using std::unique_ptr;
using std::make_unique;
using std::string;

void test_simple_sorting() {
    {
        vector<string> v;
        cls_2::sort(v.begin(), v.end());
        assert(v.empty());
    }

    {
        vector<int> v{3, 1, 2};
        cls_2::sort(v.begin(), v.end());

        assert(v == vector<int>({1, 2, 3}));
    }

    {
        vector<int> v{1, 1, 1, 1, 1, 1, 1};
        cls_2::sort(v.begin(), v.end());

        assert(v == vector<int>({1, 1, 1, 1, 1, 1, 1}));
    }

}

void test_non_copiable_sorting() {
    {
vector<unique_ptr<string>> vec;
vec.emplace_back(make_unique<string>("hello"));
vec.emplace_back(make_unique<string>("lol"));
vec.emplace_back(make_unique<string>("worldo"));
vec.emplace_back(make_unique<string>("1"));
vec.emplace_back(make_unique<string>("01"));

cls_2::sort(vec.begin(), vec.end(), [](auto& l, auto& r) { return l->size() < r->size(); });

        vector<string> result;
        std::transform(vec.cbegin(), vec.cend(), std::back_inserter(result), [](auto& p) { return *p; });

        vector<string> expected {"1", "01", "lol", "hello", "worldo"};
        assert(result == expected);
    }

    {
        struct NonCopiable {
            int value;

            NonCopiable(int value): value(value) {}
            NonCopiable(NonCopiable&& other) = default;
            NonCopiable& operator=(NonCopiable&& other) = default;

            bool operator==(NonCopiable const & other) const {
                return value == other.value;
            };

            bool operator!=(NonCopiable const & other) const {
                return value != other.value;
            };

            bool operator<(NonCopiable const& other) const {
                return value < other.value;
            }
        };

        vector<NonCopiable> v;
        v.emplace_back(NonCopiable(1));
        v.emplace_back(NonCopiable(30));
        v.emplace_back(NonCopiable(10));
        v.emplace_back(NonCopiable(1));
        v.emplace_back(NonCopiable(-50));

        cls_2::sort(v.rbegin(), v.rend());

        vector<NonCopiable> result;
        result.emplace_back(NonCopiable(30));
        result.emplace_back(NonCopiable(10));
        result.emplace_back(NonCopiable(1));
        result.emplace_back(NonCopiable(1));
        result.emplace_back(NonCopiable(-50));

        assert(v == result);
    }
}

int main() {
    test_simple_sorting();
    test_non_copiable_sorting();
}