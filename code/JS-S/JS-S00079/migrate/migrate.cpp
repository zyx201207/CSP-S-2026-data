#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    long long a[2000005];
    cin >> c >> t;
    while(t > 0)
    {
        
        long long n;
        long long d;
        cin >> n >> d;
        for(int i = 1; i <= n ; i++)
        {
            cin >> a[i];
        }
        long long ans = 0;
        long long k = (a[n] - a[1])/ (n - 1);
        if(k <= d)
        {
            int m = d/k;
            for(int i = 1; i <= m; i++)
            {
                ans = ans + n - 3 * i;
            }
            cout << ans;
        }
        else
        {
            cout << 0;
        }
        t--;
    }
    return 0;
}