#pragma once

#include "utils/Assert.h"
#include <utility>
#include <string>
#include <map>

namespace pg {

template <typename T>
class StringBimap {
    static_assert(!std::is_same<T, std::string>::value, "Type different from std::string expected");

public:
    StringBimap() = default;
    ~StringBimap() = default;

    void insert(T t, const std::string& str) {
        toStringMap_.emplace(std::make_pair(t, str));
        toValueMap_.emplace(std::make_pair(str, t));
    }

    const std::string& at(T t) const {
        auto it = toStringMap_.find(t);
        PG_ASSERT(it != toStringMap_.end());
        return it->second;
    }

    T at(const std::string& str) const {
        auto it = toValueMap_.find(str);
        PG_ASSERT(it != toValueMap_.end());
        return it->second;
    }

    bool contains(const std::string& str) const {
        const auto it = toValueMap_.find(str);
        if (it != toValueMap_.end()) {
            return true;
        }
        return false;
    }

private:
    std::map<T, std::string>    toStringMap_{};
    std::map<std::string, T>    toValueMap_{};
};

}
