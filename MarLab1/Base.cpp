#include "Base.h"

Base::Base() { std::cout << "Base: default constructor\n"; }
Base::Base(const Base&) { std::cout << "Base: copy constructor\n"; }
Base::~Base() { std::cout << "Base: destructor\n"; }
