#pragma once

#include "util.hpp"

#include "c/model/structure.hpp"
#include "c/model/comment.hpp"

using namespace stx::c;

namespace gen {

    namespace cpp {

        namespace tmplt {

            Structure* RegStructure(const util::Register& reg) {
                auto s = new Structure{t::Struct(), reg.name};
                for (const auto& opt : reg.options) {
                    s->field_add<Comment>(opt.description);
                    s->field_add({hw_type(opt), opt.name, opt.hw_size()});
                }
                auto extra = 32 - s->size();
                s->field_add({t::Uint32(), "align", extra});
                return s;
            };
            
        }; /* template */

    }; /* c++ */

}; /* generate */