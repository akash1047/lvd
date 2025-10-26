#include <exception>

import glfw;
import logger;

int main() {
  try {
    auto error_callback = [](int code, const char *description) {
      logger::critical("GLFW ERROR: {}", description);
    };

    glfw::glfw glfw{error_callback};

    glfw.no_api();
    glfw.resizable(false);

    auto window = glfw.create_window(640, 480, "Hello World");

    while (!window.should_close()) {
      glfw.poll_events();
    }

  } catch (const std::exception &e) {
    logger::critical("Exception: {}", e.what());
    return 1;
  }

  return 0;
}