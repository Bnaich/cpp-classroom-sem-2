#ifndef CLS_2_SORT_HPP
#define CLS_2_SORT_HPP

namespace cls_2 {
    template<typename RandomIter_t, typename Predicate_t = std::less<typename std::iterator_traits<RandomIter_t>::value_type>>
    void sort(RandomIter_t begin, RandomIter_t end, Predicate_t const& pred = {}) {
        std::sort(begin, end, pred);
    }
}

#endif //CLS_2_SORT_HPP
