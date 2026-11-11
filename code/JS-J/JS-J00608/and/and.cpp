#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int n,m,a[N],ans,dp[40][N],f[40],k[40];
bool vis[N];
void dfs(int cnt)
{
    if(cnt==m)
    {
        int tot=0;
        bool f=0;
        for(int i=1;i<=n;i++)
            if(vis[i])
                if(!f) tot=a[i],f=1;
                else tot=tot&a[i];
        ans=max(ans,tot);
        return;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]) vis[i]=1,dfs(cnt+1),vis[i]=0;
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<=20) dfs(0);
    else
    {
        if(m==1)
            for(int i=1;i<=n;i++)
                ans=max(ans,a[i]);
        else if(m==n)
            for(int i=1;i<=n;i++)
                ans=ans&a[i];
        else if(m==2)
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    ans=max(ans,a[i]&a[j]);
        else if(m==n-1)
        {
            for(int i=1;i<=n;i++)
                for(int j=0;j<=30;j++)
                    if(!(a[i]&(1<<j))) f[i]++;
            for(int i=0;i<=30;i++)
                if(f[i]%2==0) ans+=(1<<i);
            for(int i=1;i<=n;i++)
            {
                int res=0;
                for(int j=0;j<=30;j++)
                    k[j]=f[j];
                for(int j=0;j<=30;j++)
                    if(!(a[i]&(1<<j))) k[j]--;
                for(int j=0;j<=30;j++)
                    if(k[j]%2==0) res+=(1<<j);
                ans=max(ans,res);
            }
        }
    }
    cout<<ans;
    return 0;
}
