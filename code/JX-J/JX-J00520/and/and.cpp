#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,M=(1<<30);
int vis[N],a[N],c[N],n,m,ans,cnt[35];
void dfs(int u)
{
    if(u>m)
    {
        int z=c[1];
        for(int i=1;i<=m;i++) z&=c[i];
        ans=max(ans,z);
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        vis[i]=1;
        c[u]=a[i];
        dfs(u+1);
        c[u]=0;
        vis[i]=0;
    }
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int s=M;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s&=a[i];
        int x=a[i],tot=0;
        while(x)
        {
            tot++;
            if(x&1) cnt[tot]++;
            x>>=1;
        }
    }
    int f=1,k=0;
    for(int i=1;i<=30;i++)
    {
        if(cnt[i]!=0&&cnt[i]!=n-i+1) f=0;
        if(cnt[i]>=m) k=i;
    }
    if(f==1)
    {
        int x=0;
        for(int i=0;i<k;i++) x+=(1<<i);
        cout<<x;
        return 0;
    }
    if(m==n-1)
    {
        int x=0;
        for(int i=1;i<=n;i++) x=max(x,s^(a[i]));
        cout<<x;
        return 0;
    }
    dfs(0);
    cout<<ans;
    return 0;
}