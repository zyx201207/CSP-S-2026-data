#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;

int n,m,a[N],cnt[N],vis1[N];
bool vis[N];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>=a[i-1])  k++;
    }
    if(k==n)
    {
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            for(int j=i;j<=n;j++)
            {
                if(!vis[a[j]])  cnt[a[j]]++;
                vis[a[j]]=1;
            }
        }
        for(int i=1;i<=m;i++)  cout<<cnt[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
