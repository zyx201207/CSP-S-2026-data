#include <bits/stdc++.h>
#define ll long long
#define ts to_string
using namespace std;


int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; ll m; cin >> n >> m;
    vector<ll> data(n);
    for (int i = 0; i < n; i ++) {
        cin >> data[i];
    }
    sort(data.begin(), data.end());
    ll tt = 0;
    for (int i = 1; i < n; i ++) {
        tt += i*(data[i]-data[i-1]);
        if (tt > m) {
            cout << i; break;
        }
    }
    return 0;
}