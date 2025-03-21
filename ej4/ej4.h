#include <iostream>
#include <string>
#include <chrono>

using namespace std;


// Versión con std::string
// bool same_text(const std::string& t1, const std::string& t2, int i = 0);

// Versión con const char*
// bool same_text(const char* t1, const char* t2, int i = 0);

// Versión constexpr para evaluación en tiempo de compilación
constexpr bool same_text_constexpr(const char* t1, const char* t2, int i = 0);


