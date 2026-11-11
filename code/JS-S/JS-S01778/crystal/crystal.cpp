#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
ll a[N];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    ll m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int mx = n;
    ll sum = 0;
    for(ll i = 1; i <= n; i++)
    {
        ll tmp = (a[i] - a[i - 1]) * (i - 1);
        if(tmp <= m)
        {
            m -= tmp;
        }
        else
        {
            mx = i - 1;
            break;
        }
    }
    cout << mx;
    return 0;
}