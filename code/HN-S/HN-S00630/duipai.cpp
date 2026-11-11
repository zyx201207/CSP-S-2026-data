#include<bits/stdc++.h>
using namespace std;

int main() {
    while(1) {
        system("time ./man");
        if(system("diff man.out std.out")) {
            return cout << "NO!\n", 0;
        }
        cout << "OK\n";
    }
    return 0;
}

// ulimit -s 102400 && g++ -Wall -Wextra -O2 -std=c++14 duipai.cpp -o duipai && time ./duipai