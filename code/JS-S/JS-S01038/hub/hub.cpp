#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
#define pb push_back
#define y0 y000
#define y1 y111
#define j0 j000
#define j1 j111
typedef long long ll;
typedef unsigned long long ull;
namespace slv1{
    vector<int>G[105];
    int dp[105][105];
    int sz[105];
    int fas[105];
    bool flg[105];
    int ndp[105];
    int mxd[105];
    int dep[105];
    int outmx[105];
    int tmp_dis[105];
    void Dfs(int pt,int fa){
        fas[pt]=fa;
        sz[pt]=1;
        dp[pt][1]=0;
        mxd[pt]=0;
        dep[pt]=dep[fa]+1;
        for(int i:G[pt])if(i!=fa){
            Dfs(i,pt);
            sz[pt]+=sz[i];
            for(int j=0;j<=sz[pt];j++)ndp[j]=1000000;
            for(int j=0;j<=sz[pt]-sz[i];j++){
                for(int k=1;k<=sz[i];k++){
                    ndp[j+k]=min(ndp[j+k],max(dp[pt][j],dp[i][k]));
                }
                ndp[j]=min(ndp[j],max(dp[pt][j],mxd[i]+1));
            }
            mxd[pt]=max(mxd[pt],mxd[i]+1);
            for(int j=0;j<=sz[pt];j++)dp[pt][j]=ndp[j];
        }
    }
    void Dfs2(int pt,int fa){
        if(fa)outmx[pt]=max(outmx[pt],outmx[fa]+1);
        int mx=-2,cmx=-2;
        for(int i:G[pt])if(i!=fa){
            if(mxd[i]>=mx)cmx=mx,mx=mxd[i];
            else if(mxd[i]>=cmx)cmx=mxd[i];
        }
        for(int i:G[pt])if(i!=fa){
            if(mxd[i]==mx)outmx[i]=cmx+2;
            else outmx[i]=mx+2;
            Dfs2(i,pt);
        }
    }
    int get_lca(int u,int v){
        tmp_dis[u]=tmp_dis[v]=0;
        if(dep[u]>dep[v])swap(u,v);
        int nu=u,nv=v;
        flg[u]=flg[v]=1;
        while(dep[v]>dep[u])v=fas[v],flg[v]=1,tmp_dis[v]=dep[nv]-dep[v];
        while(u!=v){
            u=fas[u];v=fas[v];flg[u]=1;flg[v]=1;tmp_dis[u]=dep[nu]-dep[u];tmp_dis[v]=dep[nv]-dep[v];
        }
        return u;
    }
    void slv(){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            G[i].clear();
            memset(dp[i],63,sizeof(dp[i]));
            sz[i]=0;
            mxd[i]=0;
            fas[i]=0;
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            G[u].pb(v);
            G[v].pb(u);
        }
        int all_ans=10000000;
        for(int rt=1;rt<=n;rt++){
            for(int j=1;j<=n;j++)outmx[j]=0;
            for(int j=1;j<=n;j++)memset(dp[j],63,sizeof(dp[j]));
            Dfs(rt,0);
            Dfs2(rt,0);
            for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
                for(int y=1;y<=n;y++)flg[y]=0;
                int lca1=get_lca(i,j);
                if(lca1==i||lca1==j)continue;
                int ans=10000000;
                for(int y=1;y<k;y++)ans=min(ans,max(dp[i][y],dp[j][k-y]));
                int dis2=dep[i]+dep[j]-dep[lca1];
                for(int y=1;y<=n;y++)if(flg[y]){
                    int nwmx=0;
                    for(int z:G[y])if(!flg[z]){
                        if(fas[z]==y)nwmx=max(nwmx,mxd[z]+1);
                        else nwmx=max(nwmx,outmx[z]+1);
                    }
                    nwmx+=min(dis2-tmp_dis[y],tmp_dis[y]);
                    ans=max(ans,nwmx);
                }
                all_ans=min(all_ans,ans);
            }
        }
        for(int j=1;j<=n;j++)outmx[j]=0;
        for(int j=1;j<=n;j++)memset(dp[j],63,sizeof(dp[j]));
        Dfs(1,0);
        Dfs2(1,0);
        for(int i=1;i<=n;i++)all_ans=min(all_ans,max(outmx[i],dp[i][k]));
        cout<<all_ans<<'\n';
    }
}
namespace slv2{
    int dis[1005][1005];
    vector<int>G[1005];
    void Dfs(int pt,int fa,int rt){
        if(fa)dis[rt][pt]=dis[rt][fa]+1;
        else dis[rt][pt]=0;
        for(int i:G[pt])if(i!=fa)Dfs(i,pt,rt);
    }
    void slv(){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            G[u].pb(v);
            G[v].pb(u);
        }
        for(int i=1;i<=n;i++)Dfs(i,0,i);
        int ans=1000000;
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
            int nwmx=0;
            for(int k=1;k<=n;k++)nwmx=max(nwmx,min(dis[i][k],dis[j][k]));
            ans=min(ans,nwmx);
        }
        cout<<ans<<'\n';
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int c,tc;
    cin>>c>>tc;
    if(c<=6)while(tc--)slv1::slv();
    else if(c==7)while(tc--)slv2::slv();
    return 0;
}
//peimuda bless me
//MatrixGroup bless me
//hyman00 bless me
//UKBwyx bless me
//luckyclover bless me
//He_XY bless me
//daisybunny bless me
//chenmohan bless me
//xuanxuanni bless me
//Tk_hash bless me
//chennie bless me
//placeholder bless me
//Cubber bless me
//rp++