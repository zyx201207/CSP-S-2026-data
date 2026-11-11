#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 5e5 + 5;
const ll INF = 1e18;

ll a[MAXN], s = 0;
int n;
ll m;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    bool flag = true;
    int sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i >= 3)
        {
           if (a[i] - a[i - 1] != a[i - 1] - a[i - 2])
           {
               flag = false;
           }
        }
    }
    if (n > 5000 && flag)
    {
        int d = a[2] - a[1];
        if (d < 0) d = -d;
        for (int i = 2; i <= n; i++)
        {
            s += d * (i - 1);
            if (s > m)
            {
                cout << i - 1 << endl;
                return 0;
            }
        }
        cout << n << endl;
        return 0;
    }

    sort(a + 1, a + n + 1);

    /*if (n > 0)
    {
        ll l = -INF, r = INF;
        while (l < r)
        {
            ll mid = (l + r) / 2;
            ll sum = 0;
            for (int i = 1; i <= n; i++)
            {
                if (sum > m || a[i] > mid) break;
                sum += mid - a[i];
            }
            if (sum > m)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
    }*/
    for (int i = 2; i <= n; i++)
    {
        s += (a[i] - a[i - 1]) * (i - 1);
        if (s > m)
        {
            cout << i - 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}

