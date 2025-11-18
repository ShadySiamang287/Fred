#pragma once
#include <memory>
#include "Pipeline.h"

class GraphicsPipelineProvider
{
public:
	static std::shared_ptr<Pipeline> getPipeline();

	static void provide(std::shared_ptr<Pipeline> service);

private:
	static std::shared_ptr<Pipeline> service_;
};


