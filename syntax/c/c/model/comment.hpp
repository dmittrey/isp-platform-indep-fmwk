#pragma once

#include "generic/model/comment.hpp"

namespace stx {

    namespace c {

    struct Comment final : gen::Comment {
    public:
        Comment(const std::string& text) : gen::Comment(text) {}

    public:
        std::string code() const override {
            return "/* " + text + " */";
        }
    };

    }; /* c */

}; /* syntax */