#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll a[200005];
char c[200005];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    string s = " ";
    for (int i = 1; i <= n; i++) {
        ll a;
        char c;
        cin >> a >> c;
        s += string(a, c);
    }
    ll len = s.size() - 1, ans = 0;
    if (len % 2 == 1) {
        ll mid = len / 2 + 1;
        ll l = 1, r = len;
        while (l < mid && r > mid) {
            if (s[l] != s[r]) ans++;
            l++, r--;
        }
    }
    else {
        ll mid = len / 2;
        ll l = 1, r = len;
        while (l <= mid && r > mid) {
            if (s[l] != s[r]) ans++;
            l++, r--;
        }
    }
    cout << ans;
    return 0;
    
}