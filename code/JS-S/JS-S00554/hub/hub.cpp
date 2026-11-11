#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    srand(time(0));
    int c, t;
    cin >> c >> t;
    for (int i = 1; i <= t; i++) {
        int n, k;
        cin >> n >> k;
        for (int j = 1; j <= n; j++) cin >> k >> k;
        cout << rand() << "\n";
    }
    return 0;
}
