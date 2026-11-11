#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> pos(n+1);
    vector<vector<ll>> cnt_(n+1, vector<ll>(n+1, 0));
    vector<vector<ll>> len_(n+1, vector<ll>(n+1, 1ll << 60));
    for (int i = 1; i <= n; i++)    cin >> pos[i];
    for (int i = 1; i <= n; i++)
    {
        cnt_[i][i] = 1;
        len_[i][i] = 0;
    }
    for (int i = 1; i+1 <= n; i++)
    {
        int j = i+1;
        if (abs(pos[i] - pos[j]) <= m)
        {
            cnt_[i][j] = 1;
            len_[i][j] = 1;
        }
    }
    ll ans = 0;
    for (int len = 3; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l+len-1;
            ll pre_len = len_[l][r];
            for (int k = l; k < r; k++)
            {
                len_[l][r] = min(len_[l][r], len_[l][k]+len_[k+1][r]);
                if (pre_len == len_[l][r]) cnt_[l][r]++;
                if (pre_len > len_[l][r]) cnt_[l][r] = 1;
                pre_len = len_[l][r];
            }
            if (cnt_[l][r] == 2) ans++;
        }
    }
    cout << ans << endl;
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, T;
    cin >> c >> T;

    while (T--)
    {
        solve();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
