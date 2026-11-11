#include <bits/stdc++.h>
using namespace std;

int n, m, x[5000];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> x[i];

        if (x[i] == x[i-1]) {
            for(int j = 0; j <= i; j++) {
                x[j] = 0;
            }
            x[i] = x[i];
        }
    }

    cout << x;

    return 0;
}
