#pragma once

#include <utility>
#include <iterator>

using unknown = void;

template<typename Iterator_t>
class range;

template<typename Iterator_t>
range<Iterator_t> make_range(Iterator_t from, Iterator_t to);

template<typename Iterator_t>
range<Iterator_t> make_range(std::pair<Iterator_t, Iterator_t> from);