#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n;
ll a[N], cnt;
string t;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        string s;
        cin >> s;
        for (ll j = 1; j <= a[i]; j ++) t += s;
    }
    for (ll i = 0, j = t.size() - 1; i < j; i ++, j --) {
        if (t[i] != t[j]) cnt ++;
    }
    cout << cnt << "\n";
    return 0;
}
