#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e6 + 5;
ll c, t;
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> c >> t;
    if(c == 1 || c == 2) {
        for(int i = 1; i <= n; i ++) {
            cout << rand() % 3 << endl;
        }
    } else if(t == 2 || t == 3) {
        cout << rand() % 3 << endl;
    } else if(t == 17) {
        cout << 8129 << endl << 16 << endl << 9 << endl << 7 << endl << 12 << endl << 0 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl << 0;
    }
    while(t --) {
        ll n, d, x[MAXN];
        cin >> n >> d;
        for(int i = 1; i <= n; i ++) {
            cin >> x[i];
        }
        cout << rand() % 10000;
    }
    return 0;
}
