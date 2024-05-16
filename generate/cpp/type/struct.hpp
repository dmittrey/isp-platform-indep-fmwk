#pragma once

#include "interface/type.hpp"

using Utility::Type;

namespace Generate {

    namespace Types {

        namespace Cpp {

            Type make_struct() {
                return {"struct"};
            }

        }; /* Cpp */

    }; /* Types */

}; /* Generate */