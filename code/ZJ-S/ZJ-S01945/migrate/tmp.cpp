#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 5005;
typedef long long ll;

int n, pre[N], suf[N];
ll d, a[N];
int f[N][13];
ll sum[N][13];

void Main()
{
    cin >> n >> d;
    vector<pair<int, int>> ok;
    {
        int j = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i != 1 && a[i] - a[i - 1] > d)
                ok.emplace_back(j, i - 1), j = i;
        }
        if (j <= n)
            ok.emplace_back(j, n);
    }
    ll res = 0;
    for (auto _ : ok)
    {
        int l = _.first, r = _.second;
        suf[l - 1] = l;
        for (int i = l; i <= r; i++)
        {
            int &x = suf[i];
            x = suf[i - 1];
            while (x < n && a[x + 1] - a[i] <= d)
                ++x;
        }
        pre[r + 1] = r;
        for (int i = r; i >= l; i--)
        {
            int &x = pre[i];
            x = pre[i + 1];
            ll now = a[i] - a[x];
            while (x > 1 && a[i] - a[x - 1] <= d)
                --x;
        }
        for (int i = l; i <= r; i++)
            for (int j = 0; j < 13; j++)
                f[i][j] = 0;
        for (int i = l + 1; i <= r; i++)
        {
            f[i][0] = pre[i];
            sum[i][0] = pre[i];
            for (int j = 0; f[i][j]; j++)
            {
                f[i][j + 1] = f[f[i][j]][j];
                sum[i][j + 1] = sum[i][j] + sum[f[i][j]][j];
            }
        }
        res += ll(r - l) * (r - l + 1) >> 1;
        for (int i = l; i <= r; i++)
        {
            int x = suf[i];
            int cnt = 0;
            res -= x - i;
            for (int j = x + 1; j <= r; j++)
            {
                if (suf[x] < j)
                {
                    cnt += x;
                    x = suf[x];
                }
                int y = j, cnt2 = 0;
                for (int k = 12; k >= 0; k--)
                {
                    if (f[y][k] > i)
                    {
                        cnt2 += sum[y][k];
                        y = f[y][k];
                    }
                }
                if (cnt + x - cnt2 != 1)
                    --res;
            }
        }
    }
    cout << res << endl;
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int TaskCnt = 1;
    cin >> TaskCnt >> TaskCnt;
    while (TaskCnt--)
        Main();
    return 0;
}