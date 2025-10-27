#include "vulkan/vulkan_core.h"
#include <GLFW/glfw3.h>
#include <exception>
#include <vulkan/vulkan.hpp>

import glfw;
import logger;

int main() {
  try {
    auto error_callback = [](int code, const char *description) {
      logger::critical("GLFW ERROR: {}", description);
    };

    glfw::glfw glfw{error_callback};

    VkInstance instance;

    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char **glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    createInfo.enabledLayerCount = 0;

    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
      throw std::runtime_error("failed to create instance!");
    }

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::vector<VkExtensionProperties> extensions(extensionCount);

    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount,
                                           extensions.data());

    logger::info("available extensions:");

    for (const auto &extension : extensions) {
      logger::info("{}", extension.extensionName);
    }

    glfw.no_api();
    glfw.resizable(false);

    auto window = glfw.create_window(640, 480, "Hello World");

    while (!window.should_close()) {
      glfw.poll_events();
    }

    vkDestroyInstance(instance, nullptr);

  } catch (const std::exception &e) {
    logger::critical("Exception: {}", e.what());
    return 1;
  }

  return 0;
}