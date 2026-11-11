#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 +5;

int c, t, num;
int n, k;
int u[N], v[N];
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++){
            cin >> u[i] >> v[i];
        }
        num = u[1];
        cout << num <<endl;
    }
    return 0;
}
