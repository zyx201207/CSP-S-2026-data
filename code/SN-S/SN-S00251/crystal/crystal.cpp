#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 1e5+5;

ll a[MAXN];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; ll m;
    cin>>n>>m;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    
    vector<vector<ll>> diff(n+1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            diff[j].push_back(a[j] - a[i]);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll tmp = 0;
        int ta = 0;
        for (ll dif : diff[i])
        {
            if (tmp + dif <= m)
            {
                ta++;
                tmp += dif;
            }
            else break;
        }
        ans = max(ans, ta);
    }
    
    cout <<ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
