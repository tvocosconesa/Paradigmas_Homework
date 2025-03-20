#include <iostream>
#include <string>
#include <chrono>

using namespace std;

// bool same_text(string t1, string t2, int i) {
//     if (i == t2.size()) return true;

//     if (t1.size() != t2.size()) return false;

//     if (t1[i] != t2[i]) return false;

//     return same_text(t1, t2, i + 1);
// }

// bool same_text(const char*t1, const char* t2 , int i){
//     if ( t1[i] == '\0' && t2[i] == '\0' ) return true;

//     if( t1[i] != t2[i]) return false;

//     return same_text(t1 , t2 , i + 1);
// }

constexpr bool same_text(const char* t1, const char* t2, int i = 0) {
    return (t1[i] == '\0' && t2[i] == '\0') ? true :
           (t1[i] != t2[i]) ? false :
           same_text(t1, t2, i + 1);
}

int main() {
    // string t1 = "Lorem ipsum dolor sit amet consectetur adipiscing elit iaculis ut in";
    // string t2 = "Lorem ipsum dolor sit amet consectetur adipiscing elit iaculis ut in";

    constexpr const char* t1 = "Lorem ipsum dolor sit amet consectetur adipiscing, elit tempor sodales natoque nunc, parturient sociosqu condimentum tempus et.";
    constexpr const char* t2 = "Lorem ipsum dolor sit amet consectetur adipiscing, elit tempor sodales natoque nunc, parturient sociosqu condimentum tempus et.";

    auto startTime = chrono::high_resolution_clock::now();
    bool result = same_text(t1, t2, 0);
    auto endTime = chrono::high_resolution_clock::now();

    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);

    cout << "Resultado: " << result << "\n";
    cout << "Tiempo de ejecución: " << elapsedTime.count() << " nanosegundos" << endl;

    return 0;
}
