#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct base
{
    ll num;
    ll cost;
};

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n = 0, m = 0;
    cin >> n >> m;

    vector<ll> a(n + 1);
    vector<base> table(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        // ll t=0;
        // cin>>t;

        cin >> a[i];
    }

    sort(a.begin() + 1, a.end());

    ll pop_index = 0;
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            table[i].cost = 0;
            table[i].num = 1;

            continue;
        }

        // if(){

        // }
        table[i].cost = table[i - 1].cost + (a[i] - a[i - 1]) * table[i - 1].num;
        table[i].num = table[i - 1].num + 1;
        if (table[i].cost <= m)
        {
            ans = max(ans, table[i].num);
        }
        else
        {
            while (table[i].cost > m)
            {
                pop_index++;

                if (pop_index == i)
                {
                    table[i].num = 1;
                    table[i].cost = 0;
                    break;
                }

                table[i].num--;
                table[i].cost -= a[i] - a[pop_index];
            }

            ans = max(ans, table[i].num);
        }
    }

    cout << ans;

    return 0;
}