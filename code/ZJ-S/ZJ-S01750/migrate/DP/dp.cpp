#include <bits/stdc++.h>
using namespace std;
int main() {
    system("g++ ac.cpp -o ac -O2 -std=c++14");
    system("g++ wa.cpp -o wa -O2 -std=c++14");
    system("g++ data.cpp -o data -O2 -std=c++14");
    int idx = 0;
    while (1) {
        system("./data");
        system("./ac");
        system("./wa");
        if (system("diff ac.out wa.out")) {
            puts("G");
            break;
        }
        printf("ac on #%d\n", ++idx);
    }
    return 0;
}