#include <windows.h>
#include <iostream>

using namespace std;

int main() {
    if(system("fc subway5.ans subway.out")) cout << "ERROR";
    else cout << "PASS";
    return 0;
}
