#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int n, k; ll m, a[N], v[N], c[N], sumc[N], sump[N], ans;
map<ll, int> cnt;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
    for (pair<ll, int> p: cnt) v[++k] = p.first, c[k] = p.second;
    for (int i = 1; i <= k; i++)
        sumc[i] = sumc[i - 1] + c[i], sump[i] = sump[i - 1] + c[i] * v[i];
    for (int i = 1; i <= k; i++) {
        int l = 1, r = i;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (v[i] * (sumc[i - 1] - sumc[mid - 1]) - (sump[i - 1] - sump[mid - 1]) <= m)
                r = mid;
            else l = mid + 1;
        }
        int left = m - (v[i] * (sumc[i - 1] - sumc[l - 1]) - (sump[i - 1] - sump[l - 1]));
        ans = max(ans, (l > 1 ? left / (v[i] - v[l - 1]) : 0) + (sumc[i - 1] - sumc[l - 1]) + c[i]);
    }
    cout << ans << endl;
    return 0;
}