#pragma once

#include "util.hpp"
#include "lexem.hpp"

#include "c/model/function.hpp"

using namespace stx::c;

namespace gen {

    namespace c {

        namespace tmplt {

            Function* OptGetter(const util::Register& reg, const util::Option& opt) {
                auto opt_param = RVal{log_type(opt), opt.name};
                auto fd_param = RVal{t::Cint(), "fd"};

                auto opt_param_p = opt_param.ptr();

                auto func = new Function{t::Cint(), opt_selector_name(reg, opt)};

                func->params_set<RVal>({fd_param, opt_param_p});
                if (opt.is_float_point()) {
                    func->statement_add(Lexem().Concat(s_hw_type(opt)).Concat("val"));
                    func->statement_add(Lexem().Concat(t::Cint()).Concat("ret").Equal()
                                        .Ioctl().Args({fd_param.name, get_ioctl_name(reg, opt), "&val"}));
                    func->statement_add(Lexem().Star().Concat(opt_param_p.name).Equal()
                                        .Concat(to_float_name(reg, opt)).Args({"val"}));
                    func->statement_add(Lexem().Return().Concat("ret"));
                } else {
                    func->statement_add(Lexem().Return()
                                        .Ioctl().Args({fd_param.name, get_ioctl_name(reg, opt), opt_param_p.name}));
                }

                return func;
            };
            
        }; /* template */

    }; /* c */

}; /* generate */