#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k;
vector<int> a[N];
int m;
int f[N],ans[N],d[N];
void dfs(int x,int fa)
{
    f[x]=0,ans[x]=0,d[x]=d[fa]+1;
    for(int to:a[x])
    {
        if(to==fa) continue;
        dfs(to,x);
        f[x]=max(f[x],f[to]+1);
        ans[x]+=ans[to];
    }
    ans[x]+=f[x]>=m;
}
int now=1e9;
void dfs2(int x,int fa,int lmt)
{
    if(lmt+d[x]>m||!ans[x]) return ;
    now=min(now,ans[x]);
    int fir=0,sec=0;
    for(int to:a[x])
    {
        if(to==fa) continue;
        if(f[to]+1>fir) sec=fir,fir=f[to]+1;
        else if(f[to]+1>sec) sec=f[to]+1;
    }
    for(int to:a[x])
    {
        if(to==fa) continue;
        int val=f[to]+1==fir?sec:fir;
        if(val+d[x]-1<=m) dfs2(to,x,lmt);
        else dfs2(to,x,max(lmt,val-d[x]));
    }
}
bool chk()
{
    for(int i=1;i<=n;i++) //枚举根
    {
        dfs(i,0);
        if(ans[i]<=k) return 1;
        for(int to:a[i])
        {
            now=1e9,dfs2(to,i,-1e9);
            if(ans[i]-ans[to]+now<=k) return 1;
        }
    }
    return 0;
}
void run()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) a[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].emplace_back(y);
        a[y].emplace_back(x);
    }
    int l=0,r=n/2,ans=-1;
    while(l<=r)
    {
        m=(l+r)>>1;
        if(chk()) ans=m,r=m-1;
        else l=m+1;
    }
    cout<<ans<<'\n';
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--) run();
    return 0;
}