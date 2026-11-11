#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[200005],ans,num,shu;
void dfs(int u,int v,int res)
{
    if(res+1>shu)return;
    if(a[u]+d>=a[v])
    {
        if(res+1<shu)
        {
            shu=res+1;
            num=1;
        }
        else if(res+1==shu)num++;
        return;
    }
    for(int i=v-1;i>u;--i)
    {
        if(a[u]+d>=a[i])
            dfs(i,v,res+1);
    }
}
inline int keyi(int u,int v)
{
    num=0,shu=1e9;
    dfs(u,v,0);
    if(num==2)return 1;
    return 0;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;++i)cin>>a[i];
        for(int i=1;i<n;++i)
        {
            for(int j=i+3;j<=n;++j)
            {
                if(a[i]+d>=a[j])continue;
                if(keyi(i,j))ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
