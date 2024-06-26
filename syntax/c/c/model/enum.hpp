#pragma once

#include "generic/model/structure.hpp"

#include "c/types.hpp"
#include "rval.hpp"

namespace stx {

    namespace c {

        struct Enum final : gen::Structure<std::string> {

        public:
            Enum() : gen::Structure<std::string>(t::Enum(), std::nullopt) {}

        public:
            using gen::Structure<std::string>::field_add;

        public:
            std::string code() const override {
                std::string str;
                str += type.code() + ' ' + '{' + '\n';

                for (const auto &field : fields_) {
                    str += '\t' + *field + ',' + '\n';
                }

                str += std::string("}") + ';' + '\n';
                return str;
            };
        };

    }; /* c */

}; /* syntax */