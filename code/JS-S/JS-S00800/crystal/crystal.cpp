#include <bits/stdc++.h>
#define int long long
#define SIZE 600000
using namespace std;
map<int, int> cr_vals;
int n, m, a[SIZE], ans;
int mapping[SIZE], cnt[SIZE];
signed main()
{
    cin.sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cr_vals[a[i]]++;
    }
    int unique_cnt = cr_vals.size();
    int relatived = 0;
    for (auto ptr = cr_vals.begin(); ptr != cr_vals.end(); ptr++)
    {
        mapping[++relatived] = ptr->first;
        cnt[relatived] = ptr->second;
    }
    for (int i = 1; i <= unique_cnt; i++)
    {
        const auto cur_v = mapping[i];
        int useable_m = m, included = cnt[i];
        auto bkwd_ptr = i - 1;
        while (bkwd_ptr > 0 && useable_m > 0)
        {
            const auto lst_v = mapping[bkwd_ptr], lst_cnt = cnt[bkwd_ptr];
            int delta_v = cur_v - lst_v;
            if (delta_v > useable_m)
            {
                break;
            }

            int can_included = min(lst_cnt, useable_m / delta_v);
            included += can_included;
            useable_m -= lst_cnt * delta_v;
            bkwd_ptr--;
        }
        ans = max(ans, included);
    }
    cout << ans << "\n";
    return 0;
}