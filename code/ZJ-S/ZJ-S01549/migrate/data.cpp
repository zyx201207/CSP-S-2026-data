#include <bits/stdc++.h>
using namespace std;

signed main() {
    srand(time(NULL));
    freopen("migrate7.in", "w", stdout);
    cout << "0 " << 5 << endl;
    for (int T = 1; T <= 5; T++) {
        int n = 4000, k = 100;
        cout << n << " " << k << endl;
        for (int i =2;  i<= n; i++) {
            printf("%d %d\n", (rand() % (i - 1)) + 1, i);
        }
    }
    return 0;
}