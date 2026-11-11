#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=0,all=1,aa[200010],reeal[200010];
void dfs(int step,int i,int sum)
{
    if(step==m+1)
    {
        ans=max(ans,sum);
        return;
    }
    for(int j=i;j<=all;j++)
    {
        dfs(step+1,j+1,(sum&reeal[j]));
    }
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        aa[x]=1;
    }
    for(int i=1;i<=200000;i++)
    {
        if(aa[i]==1) reeal[all]=i,all++;
    }
    for(int i=1;i<=all;i++)
    {
        dfs(2,i+1,reeal[i]);
    }
    cout<<ans;
}
