#include <bits/stdc++.h>
using namespace std;
int n,m,res=INT_MIN;
int a[200005];
int vis[200005]={};
int st[200005];
int top=0;
void dfs(int dep,int last)
{
    if(dep>m)
    {
        int ans=a[st[1]];
        for(int i=2;i<=top;i++)
        {
            ans=(ans&a[st[i]]);
        }
        res=max(res,ans);
    }
    for(int i=last+1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            st[++top]=i;
            dfs(dep+1,i);
            vis[i]=0;
            top--;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,0);
    cout<<res;
    return 0;
}
