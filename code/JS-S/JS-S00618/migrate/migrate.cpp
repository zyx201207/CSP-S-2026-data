#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e6 + 10;
int x[maxn],n,d,c,T,dis[maxn];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> T;
    while(T--)
    {
        cin >> n >> d;
        for(int i = 1;i <= n;i++)
        {
            cin >> x[i];
        }
        if(n <= 3)
        {
            cout << 0 << "\n";
            continue;
        }
        int cnt = 0;
        for(int len = 4;len <= n;len++)
        {
            for(int i = 1;i + len - 1 <= n;i++)
            {
                int j = i + len - 1;
                int k = i;
                bool flag = 0;
                int dx = x[k] + d;
                int h = lower_bound(x + 1,x + n + 1,dx) - x;
                if(x[h] > dx)
                    h -= 1;
                if(h > j)
                    h = j;
                if(h == k)
                {
                    break;
                }
                k = h;
                while(k < j)
                {
                    dx = x[k] + d;
                    int h = lower_bound(x + 1,x + n + 1,dx) - x;
                    if(x[h] > dx) 
                        h -= 1;
                    if(h > j)
                        h = j;
                    if(h == k)
                    {
                        flag = 0;
                        break;
                    }
                    int tx = x[h] - d;
                    int y = lower_bound(x + 1,x + n + 1,tx) - x;
                    //cout << tx << " " << h << " " << k << " " << y << "\n";
                    if(k - y == 1)
                    {
                        if(!flag)
                        {
                            flag = 1;
                        }
                        else
                        {
                            flag = 0;
                            break;
                        }
                    }
                    else if(k - y > 1)
                    {
                        flag = 0;
                        break;
                    }
                    k = h;
                }
                //cout << "\n";
                if(flag)
                {
                    //mp[{i,j}] = 1;
                    //cout << i << " " << j << "\n";
                    cnt ++;
                }
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}