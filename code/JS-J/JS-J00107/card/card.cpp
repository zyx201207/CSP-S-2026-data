#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N];
int pre[N];
int vis[N];
int mp[N];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if(n <= 500 && m <= 300)
    {
        for(int i = 1;i <= n;i++)
        {
            memset(pre,0,sizeof(pre));
            memset(vis,0,sizeof(vis));
            for(int j = i;j <= n;j++)
            {
                if(pre[a[j]] == 0)
                {
                    pre[a[j]] = j;
                }
                else
                {
                    for(int k = pre[a[j]];k <= j - 1;k++)
                    {
                        vis[k] = 1;
                    }
                    pre[a[j]] = j;
                }
            }
            for(int j = i;j <= n;j++)
            {
                if(!vis[j])
                {
                    mp[a[j]]++;
                }
            }
        }
        for(int i = 1;i <= m;i++)
        {
            cout << mp[i] << " ";
        }
    }
    return 0;
}
