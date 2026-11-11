#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, a[5000010], t[3000010], v[3000010];


int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        vector<ll> s;
        for (ll j = 1; j <= m; j++)
        {
            v[j] = 0;
        }
        for (ll j = i; j <= n; j++)
        {
            if (v[a[j]] == 0)
            {
                s.push_back(a[j]);
                v[a[j]] = 1;
            }
            else if (v[a[j]] == 1)
            {

                while(!s.empty() && s[s.size() - 1] != a[j])
                {
                    v[s[s.size() - 1]] = 0;
                    s.pop_back();
                }
            }
        }
        for (ll i : s)
            t[i]++;
    }
    for (ll i = 1; i <= m; i++)
    {
        cout << t[i] << ' ';
    }
    return 0;
}
