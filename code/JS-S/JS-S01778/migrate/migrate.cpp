#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 5;
ll a[N]; 
int l[N], r[N];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, T;
    cin >> c >> T;
    if(c <= 10)
    {
        while(T--)
        {
            int n;
            ll d;
            cin >> n >> d;
            for(int i = 1; i <= n; i++)
            {
                cin >> a[i];
                l[i] = r[i] = 0;
            }
            for(int i = 1; i <= n; i++)
            {
                int L = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
                int R = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
                if(L == R && L == i)
                {
                    l[i] = -1;
                }
                else
                {
                    l[i] = L, r[i] = R;
                }
            }
            ll cnt = 0;
            for(ll i = 1; i <= n; i++)
            {
               
               for(ll j = i + 1; j <= n; j++)
               {
                   if(r[j] == l[i] - 1 && i + d > j - d && i + d < j && i < j - d)
                   {
                       cnt++;
                   }
               }
            }
            cout << cnt << '\n';
        }
    }
    else
    {
        while(T--)
        {
            int n;
            ll d;
            cin >> n >> d;
            for(int i = 1; i <= n; i++)
            {
                cin >> a[i];
                l[i] = r[i] = 0;
            }
            for(int i = 1; i <= n; i++)
            {
                int L = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
                int R = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
                if(L == R && L == i)
                {
                    l[i] = -1;
                }
                else
                {
                    l[i] = L, r[R]++;
                }
            }
            ll cnt = 0;
            for(int i = 1; i <= n; i++)
            {
                if(l[i] == -1)
                {
                    continue;
                }
                cnt += r[l[i] - 1];
            }
            cout << cnt << '\n';
        }
    }
    return 0;
}