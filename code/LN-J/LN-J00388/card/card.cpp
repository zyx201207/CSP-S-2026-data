#include<bits/stdc++.h>
using namespace std;
//
const int N = 5e2 + 10;
const int M = 3e2 + 10;
int n, m, a[N], ans[M], cnt[M];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    memset(cnt, 0, sizeof cnt);
    vector<int> v;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int l = 1; l <= n; l ++) {
        for (int i = l; i <= n; i ++) {
            if (l == 1 && i == 1) {
                v.push_back(a[1]);
                continue;
            }
            bool flag = false;
            for (int j : v) {
                if (a[i] == j) {
                flag = true;
                    break;
                }
            }
            if (!flag) v.push_back(a[i]);
            else {
                int k = v.size();
                for (int j = 0; j < k; j ++) {
                    if (v[j] == a[i]) {
                        v.pop_back();
                        flag = false;
                    }
                    if (!flag && !v.empty()) v.pop_back();
                }
                flag = true;
            }
            if (flag) v.push_back(a[i]);
            for (int j = 0; j < v.size(); j ++) {
                cnt[v[j]] ++;
            }
        }
        for (int j = 1; j <= m; j ++) if (cnt[j]) ans[j] ++;
        memset(cnt, 0, sizeof cnt);
        v.clear();
    }
    for (int i = 1; i <= m; i ++) cout << ans[i] << " ";
    return 0;
}
