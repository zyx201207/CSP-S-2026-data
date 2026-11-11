#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;

    cin >> n >> m;
    vector<ll> a(n + 1);
    vector<ll> b(m + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++)
    {
        b[a[i]] += i;
    }
    for(int i = 1; i <= m; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
