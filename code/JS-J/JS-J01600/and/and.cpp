#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m,ans=-1;
int b[200005];
void dfs(int dep,int sum,int j)
{
    if(sum<b[dep]) return ;
    if(dep==m)
    {
        ans=max(ans,sum);
        return ;
    }
    for(int i=j;i<=n;i++)
    {
        if(dep==0)
        {
            dfs(dep+1,a[i],i+1);
        }
        else dfs(dep+1,(sum&a[i]),i+1);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(0,0,1);
    cout<<ans;
    return 0;
}
