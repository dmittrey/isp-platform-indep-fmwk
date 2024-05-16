#pragma once

#include "interface/type.hpp"

namespace Generate {

    namespace Types {

        namespace Cpp {

            Utility::Type make_uint(const std::string &name) {
                return Type{name, "cstdint"};
            }

            Utility::Type make_uint8() {
                return make_uint("uint8_t");
            }

            Utility::Type make_uint16() {
                return make_uint("uint16_t");
            }

            Utility::Type make_uint32() {
                return make_uint("uint32_t");
            }

            Utility::Type make_uint64() {
                return make_uint("uint64_t");
            }

        }; /* Cpp */

    }; /* Types */

}; /* Generate */