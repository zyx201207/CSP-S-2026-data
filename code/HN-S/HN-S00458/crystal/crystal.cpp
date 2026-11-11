#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[500005];
int main()
{
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    ll n , m , sum = 0;
    cin >> n >> m;
    for (ll i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    int maxa = 0;
    for (ll i = 1 ; i <= n ; i++)
    {
        ll sum = 0 , c = m;
        for (ll j = 1 ; j <= n ; j++)
        {
            if (a[j] <= a[i] && (a[i] - a[j]) <= c)
            {
                sum++;
                c -= (a[i] - a[j]);
            }
        }
        if (sum > maxa)
        {
            maxa = sum;
        }
    }
    cout << maxa;
    return 0;
}
