#include "vita/App.hpp"

#include <exception>

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

  // Last resort. An exception escaping run() means the UI is already gone, but unwinding off the
  // end of main() calls std::terminate and the app dies in an abort dump; returning leaves the
  // LiveArea to come back cleanly instead. Every known throw site is handled closer in.
  try {
    vsm::vita::App app;
    return app.run();
  } catch (const std::exception &) {
    return 1;
  } catch (...) {
    return 1;
  }
}
