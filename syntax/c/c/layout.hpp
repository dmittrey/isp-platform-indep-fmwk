#pragma once

#include "generic/layout.hpp"

namespace stx {

    namespace c {

        struct Layout final : gen::Layout {
            std::string code() const override {
                std::string res;
                // res += std::string("// Headers\n");
                for (auto header : headers_)
                    res += "#include \"" + header + '\"' + '\n';

                // res += std::string("// Models\n");
                for (auto model : models_)
                    res += model->code() + '\n';

                return res;
            };
        };

    }; /* c */

}; /* syntax */