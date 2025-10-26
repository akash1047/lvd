module;

#include <GLFW/glfw3.h>
#include <stdexcept>
#include <string>

export module glfw:window;

export namespace glfw {

class window {
public:
  window(const int width, const int height, std::string title) {
    window_ptr = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window_ptr) {
      throw std::runtime_error("Failed to create GLFW window");
    }
  }

  ~window() { glfwDestroyWindow(window_ptr); }

  operator GLFWwindow *() noexcept { return window_ptr; }

  bool should_close() const noexcept {
    return glfwWindowShouldClose(window_ptr);
  }

  void set_should_close(bool value) noexcept {
    glfwSetWindowShouldClose(window_ptr, static_cast<int>(value));
  }

private:
  GLFWwindow *window_ptr;
};

} // namespace glfw
