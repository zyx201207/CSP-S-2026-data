#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans,al=INT_MAX;
bool flaga=1,flagb=1,vis[N];
int dfs(int step)
{
    if(step==m)
    {
        int res=INT_MAX;
        for(int i=1;i<=n;i++)
            if(vis[i]) res&=a[i];
        return res;
    }
    for(int i=step+1;i<=n;i++)
    {
        vis[i]=1;
        return dfs(i+1);
        vis[i]=0;
        return dfs(i+1);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if((a[i]+1)&a[i]!=0) flaga=0;
        if(a[i]!=i-1) flagb=0;
        al&=a[i];
    }
    sort(a+1,a+1+n,greater<int>());
    ans=INT_MAX;
    if(m==1) cout<<a[1];
    else if(a[1]==a[n]) cout<<a[1];
    else if(flaga||m==n)
    {
        for(int i=1;i<=m;i++)
            ans&=a[i];
        cout<<ans;
    }
    else if(m==2&&n<=2000)
    {
        ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                if(a[i]&a[j]>ans)
                    ans=a[i]&a[j];
            }
        cout<<ans;
    }
    else if(n<=20)
    {
        ans=0;
        dfs(0);
        cout<<ans;
    }
    return 0;
}
