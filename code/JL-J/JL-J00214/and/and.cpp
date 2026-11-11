#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],nax=-1,vis[1000005];
int n,m;
void dfs(int t,int cnt)
{
    if(t==m+1)
    {
        //cout<<cnt<<endl;
        nax=max(nax,cnt);
        return ;
    }
    for(int i=t;i<=n;i++)
    {
        if(vis[i])
        {
            continue;
        }
        vis[i]=1;
        if(t==1)
        {
            dfs(t+1,a[i]);
        }
        else
        {
            dfs(t+1,cnt&a[i]);
        }
        vis[i]=0;
    }
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        //ans+=s;
    }
    //cout<<ans<<endl;
    dfs(1,0);
    cout<<nax;
    return 0;
}
