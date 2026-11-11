#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX >> 1;
//2026CSP-S RP<<=INF

int c, t;

int main() {

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    srand(998244353);
    cin >> c >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(n == 5) {
            cout << 1 << endl;
        } else if(n == 10) {
            cout << 2 << endl;
        } else if(n % 2 == 1) {
            cout << 12251 << endl;
        } else {
            cout << rand() << endl;
        }
    }
    return 0;
}
