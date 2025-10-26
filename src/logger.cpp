module;

#include <print>
#include <string>
#include <unordered_map>
#include <utility>

export module logger;

namespace logger {

export enum class level {
  debug,
  info,
  warning,
  error,
  critical,
};

std::unordered_map<level, std::string> level_to_string{
    {level::debug, "DEBUG"},
    {level::info, "INFO"},
    {level::warning, "WARNING"},
    {level::error, "ERROR"},
    {level::critical, "CRITICAL"}};

class logger {
public:
  template <class... Args>
  void log(level lvl, std::format_string<Args...> format, Args... args) {
    std::print("[{}] ", level_to_string[lvl]);
    std::print(format, std::forward<Args>(args)...);
  }

  template <class... Args>
  void debug(std::format_string<Args...> format, Args... args) {
    log(level::debug, format, std::forward<Args>(args)...);
  }

  template <class... Args>
  void info(std::format_string<Args...> format, Args... args) {
    log(level::info, format, std::forward<Args>(args)...);
  }

  template <class... Args>
  void warning(std::format_string<Args...> format, Args... args) {
    log(level::warning, format, std::forward<Args>(args)...);
  }

  template <class... Args>
  void error(std::format_string<Args...> format, Args... args) {
    log(level::error, format, std::forward<Args>(args)...);
  }

  template <class... Args>
  void critical(std::format_string<Args...> format, Args... args) {
    log(level::critical, format, std::forward<Args>(args)...);
  }
};

static logger global{};

export template <class... Args>
void log(level lvl, std::format_string<Args...> format, Args... args) {
  global.log(lvl, format, std::forward<Args>(args)...);
}

export template <class... Args>
void debug(std::format_string<Args...> format, Args... args) {
  log(level::debug, format, std::forward<Args>(args)...);
}

export template <class... Args>
void info(std::format_string<Args...> format, Args... args) {
  log(level::info, format, std::forward<Args>(args)...);
}

export template <class... Args>
void warning(std::format_string<Args...> format, Args... args) {
  log(level::warning, format, std::forward<Args>(args)...);
}

export template <class... Args>
void error(std::format_string<Args...> format, Args... args) {
  log(level::error, format, std::forward<Args>(args)...);
}

export template <class... Args>
void critical(std::format_string<Args...> format, Args... args) {
  log(level::critical, format, std::forward<Args>(args)...);
}

} // namespace logger