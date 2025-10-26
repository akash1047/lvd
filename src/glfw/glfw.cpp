module;

#include <GLFW/glfw3.h>
#include <functional>
#include <print>
#include <stdexcept>
#include <string>

export module glfw;
export import :window;

export namespace glfw {

using error_callback = std::function<void(int, const char *)>;

error_callback print_on_error = [](int code, const char *message) {
  std::println(stderr, "GLFW ERROR: {}", message);
};

template <bool AutoTerminate = true> class glfw {
public:
  static void init() {
    if (!glfwInit()) {
      throw std::runtime_error("Failed to initialize GLFW");
    }
  }

  static void terminate() { glfwTerminate(); }

  void clear_error_callback() { glfwSetErrorCallback(nullptr); }

  glfw() { init(); }

  glfw(error_callback callback) {
    glfwSetErrorCallback(callback.target<void(int, const char *)>());
    init();
  }

  ~glfw() {
    if (AutoTerminate)
      terminate();
  }

  void poll_events() { glfwPollEvents(); }

  window create_window(int width, int height, std::string title) {
    return window(width, height, std::move(title));
  }

  // Window hints

  void resizable(bool value) {
    glfwWindowHint(GLFW_RESIZABLE, static_cast<int>(value));
  }

  void visible(bool value) {
    glfwWindowHint(GLFW_VISIBLE, static_cast<int>(value));
  }

  void decorated(bool value) {
    glfwWindowHint(GLFW_DECORATED, static_cast<int>(value));
  }

  void focused(bool value) {
    glfwWindowHint(GLFW_FOCUSED, static_cast<int>(value));
  }

  void auto_iconify(bool value) {
    glfwWindowHint(GLFW_AUTO_ICONIFY, static_cast<int>(value));
  }

  void floating(bool value) {
    glfwWindowHint(GLFW_FLOATING, static_cast<int>(value));
  }

  void maximized(bool value) {
    glfwWindowHint(GLFW_MAXIMIZED, static_cast<int>(value));
  }

  void center_cursor(bool value) {
    glfwWindowHint(GLFW_CENTER_CURSOR, static_cast<int>(value));
  }

  void transparent_framebuffer(bool value) {
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, static_cast<int>(value));
  }

  void focus_on_show(bool value) {
    glfwWindowHint(GLFW_FOCUS_ON_SHOW, static_cast<int>(value));
  }

  void scale_to_monitor(bool value) {
    glfwWindowHint(GLFW_SCALE_TO_MONITOR, static_cast<int>(value));
  }

  void scale_framebuffer(bool value) {
    glfwWindowHint(GLFW_SCALE_FRAMEBUFFER, static_cast<int>(value));
  }

  void mouse_passthrough(bool value) {
    glfwWindowHint(GLFW_MOUSE_PASSTHROUGH, static_cast<int>(value));
  }

  void position(int x, int y) {
    glfwWindowHint(GLFW_POSITION_X, x);
    glfwWindowHint(GLFW_POSITION_Y, y);
  }

  void position_x(int x) { glfwWindowHint(GLFW_POSITION_X, x); }

  void position_y(int y) { glfwWindowHint(GLFW_POSITION_Y, y); }

  // Framebuffer related hints
  void red_bits(int bits) { glfwWindowHint(GLFW_RED_BITS, bits); }

  void green_bits(int bits) { glfwWindowHint(GLFW_GREEN_BITS, bits); }

  void blue_bits(int bits) { glfwWindowHint(GLFW_BLUE_BITS, bits); }

  void alpha_bits(int bits) { glfwWindowHint(GLFW_ALPHA_BITS, bits); }

  void depth_bits(int bits) { glfwWindowHint(GLFW_DEPTH_BITS, bits); }

  void stencil_bits(int bits) { glfwWindowHint(GLFW_STENCIL_BITS, bits); }

  void accum_red_bits(int bits) { glfwWindowHint(GLFW_ACCUM_RED_BITS, bits); }

  void accum_green_bits(int bits) {
    glfwWindowHint(GLFW_ACCUM_GREEN_BITS, bits);
  }

  void accum_blue_bits(int bits) { glfwWindowHint(GLFW_ACCUM_BLUE_BITS, bits); }

  void accum_alpha_bits(int bits) {
    glfwWindowHint(GLFW_ACCUM_ALPHA_BITS, bits);
  }

  void aux_buffers(int count) { glfwWindowHint(GLFW_AUX_BUFFERS, count); }

  void stereo(bool value) {
    glfwWindowHint(GLFW_STEREO, static_cast<int>(value));
  }

  void samples(int count) { glfwWindowHint(GLFW_SAMPLES, count); }

  void srgb_capable(bool value) {
    glfwWindowHint(GLFW_SRGB_CAPABLE, static_cast<int>(value));
  }

  void doublebuffer(bool value) {
    glfwWindowHint(GLFW_DOUBLEBUFFER, static_cast<int>(value));
  }

  // Monitor related hints
  void refresh_rate(int rate) { glfwWindowHint(GLFW_REFRESH_RATE, rate); }

  // Context related hints
  void client_api(int api) { glfwWindowHint(GLFW_CLIENT_API, api); }

  void no_api() { glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); }

  void opengl_api() { glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API); }

  void opengl_es_api() { glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API); }

  void context_creation_api(int api) {
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, api);
  }

  void native_context_api() {
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_NATIVE_CONTEXT_API);
  }

  void egl_context_api() {
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
  }

  void osmesa_context_api() {
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_OSMESA_CONTEXT_API);
  }

  void context_version(int major, int minor) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
  }

  void context_version_major(int major) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
  }

  void context_version_minor(int minor) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
  }

  void opengl_forward_compat(bool value) {
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, static_cast<int>(value));
  }

  void context_debug(bool value) {
    glfwWindowHint(GLFW_CONTEXT_DEBUG, static_cast<int>(value));
  }

  void opengl_debug_context(bool value) {
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, static_cast<int>(value));
  }

  void opengl_profile(int profile) {
    glfwWindowHint(GLFW_OPENGL_PROFILE, profile);
  }

  void opengl_core_profile() {
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  }

  void opengl_compat_profile() {
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
  }

  void opengl_any_profile() {
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
  }

  void context_robustness(int robustness) {
    glfwWindowHint(GLFW_CONTEXT_ROBUSTNESS, robustness);
  }

  void no_robustness() {
    glfwWindowHint(GLFW_CONTEXT_ROBUSTNESS, GLFW_NO_ROBUSTNESS);
  }

  void no_reset_notification() {
    glfwWindowHint(GLFW_CONTEXT_ROBUSTNESS, GLFW_NO_RESET_NOTIFICATION);
  }

  void lose_context_on_reset() {
    glfwWindowHint(GLFW_CONTEXT_ROBUSTNESS, GLFW_LOSE_CONTEXT_ON_RESET);
  }

  void context_release_behavior(int behavior) {
    glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, behavior);
  }

  void any_release_behavior() {
    glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, GLFW_ANY_RELEASE_BEHAVIOR);
  }

  void release_behavior_flush() {
    glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, GLFW_RELEASE_BEHAVIOR_FLUSH);
  }

  void release_behavior_none() {
    glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, GLFW_RELEASE_BEHAVIOR_NONE);
  }

  void context_no_error(bool value) {
    glfwWindowHint(GLFW_CONTEXT_NO_ERROR, static_cast<int>(value));
  }

  // Win32 specific hints
  void win32_keyboard_menu(bool value) {
    glfwWindowHint(GLFW_WIN32_KEYBOARD_MENU, static_cast<int>(value));
  }

  void win32_showdefault(bool value) {
    glfwWindowHint(GLFW_WIN32_SHOWDEFAULT, static_cast<int>(value));
  }

  // macOS specific hints
  void cocoa_frame_name(const char *name) {
    glfwWindowHintString(GLFW_COCOA_FRAME_NAME, name);
  }

  void cocoa_graphics_switching(bool value) {
    glfwWindowHint(GLFW_COCOA_GRAPHICS_SWITCHING, static_cast<int>(value));
  }

  // Wayland specific hints
  void wayland_app_id(const char *app_id) {
    glfwWindowHintString(GLFW_WAYLAND_APP_ID, app_id);
  }

  // X11 specific hints
  void x11_class_name(const char *class_name) {
    glfwWindowHintString(GLFW_X11_CLASS_NAME, class_name);
  }

  void x11_instance_name(const char *instance_name) {
    glfwWindowHintString(GLFW_X11_INSTANCE_NAME, instance_name);
  }

  void default_window_hints() { glfwDefaultWindowHints(); }
};

} // namespace glfw
