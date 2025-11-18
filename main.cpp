#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <memory>

#include "SceneManager.h"
#include "GraphicsPipelineProvider.h"

#ifndef Vulkan
#include "VulkanPipeline.h"
#endif // !VULKAN


int main() {
#ifndef Vulkan
    GraphicsPipelineProvider::provide(std::shared_ptr<Pipeline>(new VulkanPipeline));
#endif // Vulkan


    GLFWwindow* window;
    std::shared_ptr<SceneManager> sceneManager = SceneManager::getInstance();
    sceneManager->configure(10);
    sceneManager->addScene(std::make_unique<Scene>("default"));

    if (!glfwInit()) {
        return -1;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(1280, 720, "Fred game engine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    GraphicsPipelineProvider::getPipeline()->init(window);

    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    GraphicsPipelineProvider::getPipeline()->cleanup();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
