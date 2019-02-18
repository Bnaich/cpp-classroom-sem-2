#ifndef CLS_2_UNIQUE_PTR_HPP
#define CLS_2_UNIQUE_PTR_HPP

#include <memory>

namespace cls_2 {
    template <typename T>
    using unique_ptr = std::unique_ptr<T>;

    template <typename T>
    unique_ptr<T> make_unique(...) {
        return {};
    }
}

#endif //CLS_2_UNIQUE_PTR_HPP
