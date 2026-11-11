#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[200005], ans;
signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    if(m == 1)
        cout << a[1];
    else
    {
        if(m == n)
        {
            ans = a[1];
            for(int i = 2;i <= n;i++)
                ans = (ans & a[i]);
            cout << ans;
        }
        else
        {
            if(m == 2)
            {
                for(int i = 1;i < n;i++)
                {
                    for(int j = i + 1;j <= n;j++)
                        ans = max((a[i] & a[j]), ans);
                }
                cout << ans;
            }
        }
    }
    return 0;
}
