#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int pos[N],to[N];
int n,d;
int f[N];//被多少点只走长边唯一抵达
int g[N];//除最后一步外只走长边，能唯一抵达多少点（注意考虑i-1）
int h[N];//特殊的一步！
void run()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>pos[i];
    for(int i=0;i<=n+1;i++) f[i]=g[i]=h[i]=0;
    for(int i=n,j=n;i;i--)
    {
        while(pos[j]-pos[i]>d) j--;
        to[i]=j;
    }
    for(int i=1;i<=n;i++)
    {
        if(i==to[i]) continue;
        f[to[i]]++;//i自己作为起点
        if(to[i-1]<to[i]) f[to[i]]+=f[i];
    }
    for(int i=n;i;i--)
    {
        if(to[i-1]==to[i]||to[i]==i) continue;
        g[i]=g[to[i]]+to[i]-max(i,to[i-1]);
    }
    for(int i=1;i<=n;i++)
    {
        if(to[i]<=i+1) continue;
        h[to[i]]++;//自己作为起点
        if(to[i-1]<to[i]-1) h[to[i]]+=f[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(i>2&&to[i-2]==to[i]) continue;
        // cerr<<h[i]<<'\n';
        int lmt=max(i,i>2?to[i-2]:0ll);
        //这是最后一步
        ans+=max(0ll,to[i-1]-lmt)*h[i];
        //这不是最后一步
        if(to[i-1]==to[i]) ans+=g[to[i]]*h[i];
        // cout<<i<<' '<<ans<<'\n';
    }
    cout<<ans<<'\n';
}
signed main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--) run();
    return 0;
}