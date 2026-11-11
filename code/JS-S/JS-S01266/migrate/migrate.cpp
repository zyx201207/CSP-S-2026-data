#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        int a[n + 10];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int cha = a[2] - a[1];
        if(2 * cha <= d && 3 * cha > d) {
            cout << (n - 4) + 1 << endl;
        }else {
            cout << "0" << endl;
        }
    }
    return 0;
}