#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 5000005;
ll a[N];

int main()
{

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, cnt = 0;
    ll m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    ll h = (n + 1) / 2;
    ll s = a[h];

    for(int i = h; i >= 1; i--)
    {
        ll u = s - a[i];
        if(m < u) break;
        else
        {
            m -= u;
            cnt++;
        }
    }
    for(int i = h + 1; i <= n; i++)
    {
        if(a[i] == s) cnt++;
        else break;
    }
    cout << cnt;
    return 0;
}
