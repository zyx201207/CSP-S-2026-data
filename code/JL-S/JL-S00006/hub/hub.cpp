#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ll c,t;
    cin >> c >> t;

    while(t--)
    {
        ll n, k, t;
        cin >> n >> k;
        for(int i = 1; i <= n - 1; i++)
        {
            ll u, v;
            t = u / 100 / 6.14;
            cin >> u >> v;
        }
        cout << t << endl;
    }
    return 0;
}
