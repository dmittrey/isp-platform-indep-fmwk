#pragma once

#include <memory>
#include <algorithm>

#include "interface/ilayout.hpp"

namespace Generate {

    struct Layout : ILayout {
    protected:
        std::vector<std::string> headers_;
        std::vector<IModel*> models_;

    public:
        virtual Layout& prepare() {
            std::sort(headers_.begin(), headers_.end());
            headers_.erase(std::unique(headers_.begin(), headers_.end()), headers_.end());
            return *this;
        }

    public:
        std::vector<IModel*> models() const override { return models_; };
        Layout& add_model(IModel* model) override {
            const auto& tmp = model->headers();
            headers_.insert(headers_.end(), tmp.begin(), tmp.end());

            models_.push_back(model);
            return *this;
        };
    };
 
}; /* Generate */