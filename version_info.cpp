#include <iostream>

void print_compiler_info() {
#if defined(__clang__)
  std::cout << "Clang version " << __clang_version__ << std::endl;
#elif defined(__GNUC__)
  std::cout << "GCC version " << __GNUC__ << "."
                              << __GNUC_MINOR__ << "."
                              << __GNUC_PATCHLEVEL__ << std::endl;
#else
  std::cout << "Unknown compiler" << std::endl;
#endif
}

void print_standard_library_info() {
#if defined(_LIBCPP_VERSION)
  std::cout << "libc++ version " << _LIBCPP_VERSION << std::endl;
#elif defined(__GLIBCXX__)
  std::cout << "libstdc++ version " << __GLIBCXX__ << std::endl;
#else
  std::cout << "Unknown STL library" << std::endl;
#endif
}

void print_language_info() {
  std::cout << "C++ dialect " << __cplusplus << std::endl;
}

int main() {
  std::string banner(10, '-');
  std::string info_str = " Version Info ";
  std::cout << banner << info_str << banner << std::endl;
  print_compiler_info();
  print_standard_library_info();
  print_language_info();
  std::cout << std::string(20 + info_str.size(), '-') << std::endl;
}