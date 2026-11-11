#include <bits/stdc++.h>
using namespace std;
int n,m,a[50005],ans[50005],pos[50005],lst[50005],vis[50005],bo[50005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    for(int i = 1;i <= n;i++)
    {
        memset(pos,0,sizeof(pos));
        memset(lst,-0x3f,sizeof(lst));
        memset(vis,0,sizeof(vis));
        memset(bo,0,sizeof(bo));
        for(int j = i;j <= n;j++)
        {
            if(!(pos[a[j]])) pos[a[j]] = j;
            else
            {
                lst[a[j]] = pos[a[j]];
                pos[a[j]] = 0;
            }
        }
        for(int j = i;j <= n;j++)
        {
            if(lst[a[j]] != -0x3f3f3f3f)
                for(int k = lst[a[j]];k <= j-1;k++)
                    vis[k] = 1;
        }
        for(int j = i;j <= n;j++)
            if(vis[j] == 0 && bo[a[j]] == 0)
            {
                ans[a[j]]++;
                bo[a[j]] = 1;
            }
    }
    for(int i = 1;i <= m;i++)
        cout << ans[i];
}
