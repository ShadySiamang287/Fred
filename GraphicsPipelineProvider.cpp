#include "GraphicsPipelineProvider.h"

#include "NullPipeline.h"

std::shared_ptr<Pipeline> GraphicsPipelineProvider::getPipeline()
{
    if (!service_) {
        static std::shared_ptr<Pipeline> nullPipeline = std::make_shared<NullPipeline>();
        return nullPipeline;
    }
    return service_;
}

void GraphicsPipelineProvider::provide(std::shared_ptr<Pipeline> service)
{
    service_ = service;
}

std::shared_ptr<Pipeline> GraphicsPipelineProvider::service_ = nullptr;