#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 2e6 + 5;
typedef long long ll;

int n, pre[N], suf[N];
ll d, a[N];
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
        res += ll(r - l) * (r - l + 1) >> 1;
        for (int i = l; i <= r; i++)
        {
            for (int j = i + 1; j <= r; j++)
            {
                vector<int> v;
                v.emplace_back(i);
                int x = i;
                while (x < j)
                {
                    x = min(j, suf[x]);
                    v.emplace_back(x);
                }
                int y = j;
                int cnt = 0;
                for (int k = (int)v.size() - 2; k > 0; k--)
                {
                    y = max(i, pre[y]);
                    cnt += v[k] - y;
                }
                if (cnt != 1)
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