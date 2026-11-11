#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000000],vis[1000000],ans[1000000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int d=n;
    while(d){
        for(int i=n-d+1;i<=n;i++)
        {

            if(vis[a[i]])
            {
                for(int j=vis[a[i]];j<i;j++)
                {
                    vis[vis[a[j]]]=0;
                }

            }
            else
            {
                vis[a[i]]=i;
            }

        }
            for(int j=1;j<=m;j++)
            {
                if(vis[a[j]])
                    ans[j]++;
            }
        d--;
    }
    for(int j=1;j<=m;j++)
        {
            cout<<ans[j]<<" ";
        }
    return 0;
}
