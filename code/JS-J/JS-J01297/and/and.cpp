#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[200005];
int ans;
queue<int>q;
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int>v;
    for (int i = 1; i <= n; i++) v.push_back(i);
    for (int i = 30; i >= 0; i--) {
        int cnt = 0;
        for (int j : v) {
            if ((a[j] >> i) & 1) cnt++;
        }
        if (cnt < m) continue;
        else {
            ans += (1 << i);
            for (int j : v) {
                if ((a[j] >> i) & 1) q.push(j);
            }
            v.clear();
            while (q.size()) {
                v.push_back(q.front());
                q.pop();
            }
        }
    }
    cout << ans;
}