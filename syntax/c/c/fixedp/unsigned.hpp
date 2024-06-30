#pragma once

#include "c/types.hpp"
#include "c/model/function.hpp"
#include "c/model/rval.hpp"

namespace stx {

    namespace c {

        namespace fixedp {

            struct FloatToUnsignedFixedFunction final : Function {
                FloatToUnsignedFixedFunction(const Type& ret_type, const std::string &name, const std::string& scale_macro, uint8_t fract_cnt)
                    : Function(ret_type, name) {
                        gen::Function::params_set<RVal>({{t::Double(), "float_val"}});
                        gen::Function::statement_add("return (" + ret_type.code() +")((float_val) * " + scale_macro + '(' + std::to_string(fract_cnt) + ')' + ")");
                    }
            };

            struct UnsignedFixedToFloatFunction final : Function {
                UnsignedFixedToFloatFunction(Type ret_type, const std::string &name, Type fix_type, const std::string& scale_macro, uint8_t fract_cnt)
                    : Function(ret_type, name) {
                        gen::Function::params_set<RVal>({{fix_type, "fixed_val"}});
                        gen::Function::statement_add("return (" + ret_type.code() +")((fixed_val) / " + scale_macro + '(' + std::to_string(fract_cnt) + ')' + ")");
                    }
            };

        }; /* fixed-point */

    }; /* c */

}; /* syntax */