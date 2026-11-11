#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long 
#define sqr(x) ((x) * (x))
using namespace std;

constexpr unsigned int NR = 2e6 + 5;
int CID, n, pos[NR], minn[NR];
ll d, a[NR], cnt[NR];
vector<ll> v[NR], sum[NR];
void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++ i)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; ++ i) {
        for (int j = i; j <= n; ++ j) {
            minn[j] = 1e9;
            cnt[j] = 0;
        }
        minn[i] = 0;
        cnt[i] = 1;
        int l = i;
        v[0].emplace_back(i);
        sum[0].emplace_back(1);
        int maxn = 0;
        for (int j = i + 1; j <= n; ++ j) {
            if (a[j] - a[j - 1] > d)
                break;
            while (a[j] - a[l] > d)
                l ++;
            minn[j] = minn[l] + 1;
            while (a[j] - a[v[minn[l]][pos[minn[l]]]] > d)
                pos[minn[l]] ++;
            cnt[j] = sum[minn[l]].back();
            if (pos[minn[l]] > 0)
                cnt[j] -= sum[minn[l]][pos[minn[l]] - 1];
            cnt[j] = min(cnt[j], 1000000000ll);
            v[minn[j]].emplace_back(j);
            ll tmp = cnt[j];
            if (!sum[minn[j]].empty())
                tmp += sum[minn[j]].back();
            sum[minn[j]].emplace_back(tmp);
            ans += (cnt[j] == 2);
            maxn = max(maxn, minn[j]);
        }
        for (int j = 0; j <= maxn; ++ j) {
            v[j].clear();
            sum[j].clear();
            pos[j] = 0;
        }
    }
    cout << ans << '\n';
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int oT_To = 1;
    cin >> CID >> oT_To;
    while (oT_To --)
        solve();
    return 0; 
}
