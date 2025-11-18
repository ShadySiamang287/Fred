#include "NullPipeline.h"
#include <iostream>

void NullPipeline::DrawVerticies()
{
	std::cout << "No pipeline set\n";
}

void NullPipeline::init(GLFWwindow* window)
{
	std::cout << "No pipeline set\n";
}

void NullPipeline::cleanup()
{
	std::cout << "No pipeline set\n";
}
