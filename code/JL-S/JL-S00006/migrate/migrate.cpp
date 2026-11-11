#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2000005;

ll x[N], cnt = 0, n, d;

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll c, t;
    cin >> c >> t;

    while(t--)
    {
        cin >> n >> d;
        bool ok = 1;
        ll j = 1;
        cin >> x[1] >> x[2];
        j = x[2] - x[1];
        for(int i = 3; i <= n; i++)
        {
            cin >> x[i];
            if(x[i] - x[i - 1] != j) ok = 0;
        }

        if(ok && j <= d)
        {
            ll cnt = 0, s = d * 2;
            for(int i = 1; i <= n; i++)
            {
                ll h = n - i + 1;
                if(h < s) break;
                h -= s;
                cnt++;

                if(h >= d) cnt += (h / d);
            }
            cout << cnt << "\n";
        }
        else cout << 1 << "\n";
    }

    return 0;
}
