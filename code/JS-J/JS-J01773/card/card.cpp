#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], id[300005];
map<int, int> mp, ans;
vector<int> ve;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        ve.clear();
        ve.push_back(0);
        for (int j = 1; j <= m; j++) mp[j] = 0, id[j] = 0;
        for (int j = i; j <= n; j++) {
            if (mp[a[j]]) {
                for (int k = ve.size() - 1; k >= id[a[j]]; k--) {
                    ve.pop_back();
                    mp[ve[k]]--;
                }
            }
            mp[a[j]]++;
            int x = ve.size();
            id[a[j]] = x;
            ve.push_back(a[j]);
        }
        for (int j = 1; j <= m; j++) ans[j] += mp[j];
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}
