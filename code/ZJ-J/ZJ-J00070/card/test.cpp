#include <bits/stdc++.h>
using namespace std;

int a[3] = {1,2,3};

int main() {
    cout << lower_bound(a, a + 3, 1001) - a;
}