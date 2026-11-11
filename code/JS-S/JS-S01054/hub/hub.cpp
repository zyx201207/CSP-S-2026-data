#include<bits/stdc++.h>
#define int long long
#define ls (p<<1)
#define rs (ls|1)
#define F first
#define S second
using namespace std;
void fileopen(string s)
{
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
vector<int> g[2000003];
int f[2000003],vis[2000003];
void dfs(int x)
{
    vis[x]=true;
    for(auto y:g[x])if(!vis[y]&&f[y])dfs(y);
}
int sfd(int x,int fa)
{
    if(f[x])return 0;
    int mn=INT_MAX;
    for(auto y:g[x])if(y!=fa)mn=min(mn,sfd(y,x));
    return mn+1;
}
void solve()
{
    int n,k,i,x,y,ans=INT_MAX;
    cin>>n>>k;
    for(i=1;i<=n;i++)g[i].clear();
    for(i=1;i<n;i++)cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
    for(int s=0;s<(1<<n);s++)
    {
        if(__builtin_popcount(s)!=k)continue;
        for(i=1;i<=n;i++)if((s>>(i-1))&1)f[i]=true;else f[i]=false;
        for(i=1;i<=n;i++)vis[i]=false;
        int ct=0;
        for(i=1;i<=n;i++)
        {
            if(!f[i])continue;
            if(!vis[i])ct++,dfs(i);
        }
        if(ct>2)continue;
        int mx=-1;
        for(i=1;i<=n;i++)mx=max(mx,sfd(i,-1));
        ans=min(ans,mx);
        /*
        cout<<"When s="<<s<<", mx="<<mx<<", ans="<<ans<<'\n';
        for(i=1;i<=n;i++)if(f[i])cout<<i<<' ';cout<<'\n';
        cerr<<"ct="<<ct<<'\n';
        */
    }
    cout<<ans<<'\n';
}
signed main()
{
    fileopen("hub");
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testcase,T;
    cin>>testcase>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
/*
17:57 算了 直接暴力吧
18:13 严肃通过大样例1~2

期望15pts


更暗 夜更暗 回头空街一段
弥漫 风弥漫 四季推波助澜
大雨将悲欢都冲淡 往事在风中肆无忌惮
看似过去 却从未走远 拥抱的温存 梦醒一半
道别声还在耳畔 诉说声不忍再看
命运声风轻云淡 让是非与你无关
我的慌乱我的伪装 我的不舍被你 一眼看穿
情剪不断 也不愿剪断 再见难说 故事还没完

道别 又道别 汽笛声在呼唤
想念 还想念 往事被泪晕染
月光将迷雾都驱散 回忆似梦境又似迷幻
看似过去 却还在纠缠 拥抱的温存 随风而散
道别声还在耳畔 诉说声不忍再看
命运声风轻云淡 让是非与你无关
我的慌乱我的伪装 我的不舍被你 一眼看穿
情剪不断 也不愿剪断 再见难说 故事还没完

 _____ __ ___99.?

㟒鎾䋪嵶䜏㛣uℹ筽巭
錒䓾枤䃿㗻㺢䣺韕㛎
蓙䗼乼v喸哖凩
*/
