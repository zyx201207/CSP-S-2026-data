#include <bits/stdc++.h>

using namespace std;

int T;

int main() {
    while (++T) {
        if (T % 100 == 0) cout << T << '\n';
        system("./data > in.txt");
        system("./a < in.txt > out1.txt");
        system("./b < in.txt > out2.txt");
        if (system("diff -w out1.txt out2.txt")) {
            cout << "WA\n";
            break;
        }
    }
    return 0;
}