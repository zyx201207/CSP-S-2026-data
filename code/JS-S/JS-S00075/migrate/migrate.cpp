#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int a[N];
void solve()
{
    int n,d;
    cin >> n >> d;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if(n <= 9)
    {
        int cnt = 0;
        int ret = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                if(a[j] - a[i] > d)
                {
                    for(int k = i + 1;k < j;k++)
                    {
                        if(a[j] - a[k] <= d && a[k] - a[i] <= d)
                        {
                            ret++;
                        }
                    }
                }
            }
        }
        if(ret == 2)cnt++;
        cout << cnt << endl;
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t-->0)solve();
    return 0;
}
