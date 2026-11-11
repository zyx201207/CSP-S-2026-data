#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(time(0));

int main() {
    cout << uniform_int_distribution<int>(0, 1e9)(mrand) << ' ';
    cout << uniform_int_distribution<int>(0, 1e9)(mrand) << ' ';
    return 0;
}