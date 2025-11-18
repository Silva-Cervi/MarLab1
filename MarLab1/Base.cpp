#include "Base.h"
#include <iostream>

Base::Base() { std::cout << "Base: конструктор по умолчанию\n"; }
Base::Base(const Base&) { std::cout << "Base: конструктор копирования\n"; }
Base::~Base() { std::cout << "Base: деструктор\n"; }
