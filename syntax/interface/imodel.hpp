#pragma once

#include <vector>
#include <string>

namespace Syntax {

    /* Rendering object */
    struct IModel {
        virtual const std::vector<std::string>& headers() const & = 0;
        virtual std::string code() const = 0;
        virtual ~IModel() {};
    };

}; /* Syntax */