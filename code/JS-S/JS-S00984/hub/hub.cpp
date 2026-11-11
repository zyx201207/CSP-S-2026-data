#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,f[N],g[N],dep[N],mx,fa[N],dis[N];
vector<int> vc[N];
void dfs0(int x,int ff){
    dep[x]=dep[ff]+1,fa[x]=ff;
    if(dep[x]>dep[mx])mx=x;
    for(int y:vc[x])if(y!=ff)dfs0(y,x);
}
int dp[N],Mid,ch[N],rt;
int dfn[N],rnk[N],F[N],dfc,all,D[N];
int pt[N],lim[N];
void dfs(int x,int fr){
    F[x]=fr,dfn[x]=++dfc,rnk[dfc]=x;
    f[x]=g[x]=0,dp[x]=ch[x]=1,D[x]=D[fr]+1;
    for(int y:vc[x])if(y!=fr){
        dfs(y,x);
        if(f[y]+1>Mid)dp[x]+=dp[y];
        else ch[y]=0;
        if(f[y]+1>=f[x])g[x]=f[x],f[x]=f[y]+1;
        else g[x]=max(g[x],f[y]+1);
    }
}
int st[20][N],G[20][N],V[N];
void dfs3(int x,int fr){
    for(int y:vc[x])if(y!=fr){
        int ln;
        if(f[y]+1==f[x])ln=g[x];
        else ln=f[x];
        lim[y]=max(lim[x],D[x]+ln-Mid+1);
        V[y]=D[x]+ln-Mid+1;
        lim[y]=min(lim[y],D[y]);
        st[0][y]=x,G[0][y]=ln-D[x];
        for(int i=1;i<20;i++)st[i][y]=st[i-1][st[i-1][y]],G[i][y]=max(G[i-1][y],G[i-1][st[i-1][y]]);
        dfs3(y,x);
    }
}
int fd(int x,int lm){
    for(int i=19;~i;i--)if(G[i][x]<=lm)x=st[i][x];
    return x;
}
bool dfs2(int x,int fr){
    pt[D[x]]=x;
    if(fr){
        int nw,ln,ct=0;
        int y=fd(x,Mid-D[x]);
        // if(Mid==1)cout<<"# "<<x<<' '<<y<<' '<<rt<<' '<<lim[y]<<'\n';
        if(all-ch[y]+dp[x]<=m)return 1;
        if(y!=rt&&lim[y]<=D[F[y]]&&all-ch[pt[lim[y]]]+dp[x]<=m)return 1;
        int tp=lim[y],tp2=D[y],ls=y;
        // int tm=-1e9;
        // while(y!=rt){
        //     nw=F[y],ct++;
        //     if(f[nw]==f[y]+1)ln=g[nw];
        //     else ln=f[nw];
        //     // if(ct+ln>Mid)
        //     tm=max(tm,ln);
        //     tm++;
        //     if(tm>Mid)break;
        //     y=nw;
        //     if(dp[x]+all-ch[y]<=m){
        //         if(Mid==9){
        //             cout<<tp<<' '<<D[y]<<' '<<tp2<<'\n';
        //             for(int z=ls;z!=y;z=F[z])cout<<V[z]<<' ';
        //             cout<<'\n';
        //         }
        //         // assert(Mid!=9||y!=rt);
        //         return 1;
        //     }
        // }
    }
    for(int y:vc[x])if(y!=fr&&dfs2(y,x))return 1;
    return 0;
}
bool chk(int mid){
    if(dep[mx]<=mid+1)return 1;
    int t=mx;
    for(int i=1;i<=mid;i++)t=fa[t];
    dfc=0,Mid=mid,dfs(t,0);
    for(int i=dfc;i;i--)ch[F[rnk[i]]]+=ch[rnk[i]];
    for(int i=0;i<20;i++)st[i][t]=t,G[i][t]=1e9;
    lim[t]=1,dfs3(t,0);
    rt=t,dis[t]=1e9;
    for(int i=2;i<=dfc;i++){
        int x=rnk[i];
        if(ch[F[x]])dis[x]=1;
        else dis[x]=dis[F[x]]+1;
    }
    // if(mid==1)cout<<"## "<<t<<' '<<dp[t]<<'\n';
    if(dp[t]<=m)return 1;
    all=dp[t];
    return dfs2(t,0);
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)vc[i].clear();
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        vc[x].push_back(y);
        vc[y].push_back(x);
    }
    if(m==n){
        cout<<"0\n";
        return ;
    }
    mx=0,dfs0(1,0);
    int L=1,R=n-1,mid,res=n-1;
    while(L<=R){
        mid=L+R>>1;
        if(chk(mid))res=mid,R=mid-1;
        else L=mid+1;
    }
    cout<<res<<'\n';
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int cc,tc;
    cin>>cc>>tc;
    while(tc--)solve();
    return 0;
}