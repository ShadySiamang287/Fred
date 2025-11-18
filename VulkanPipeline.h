#pragma once
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include "Pipeline.h"

class VulkanPipeline : public Pipeline
{
public:
	virtual void DrawVerticies() override;
	virtual void init(GLFWwindow* window) override;
	virtual void cleanup() override;

private:
	void initVulkan();
	void createInstance();

	bool checkValidationLayerSupport();

	VkInstance instance;

#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif

	const std::vector<const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation"
	};
};

