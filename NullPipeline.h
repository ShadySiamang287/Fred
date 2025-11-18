#pragma once
#include "Pipeline.h"
class NullPipeline : public Pipeline
{
public:
	virtual void DrawVerticies() override;
	virtual void init(GLFWwindow* window) override;
	virtual void cleanup() override;
};

