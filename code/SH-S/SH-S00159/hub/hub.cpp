#include<iostream>
#include<vector>
using namespace std;
using ll=long long;
const int MAXN=2e6+5;
const int MAXN1=1005;
int n,k;
int ans=0;
vector<int> G[MAXN];
void solve1314(){
    int m=n/2;
    ans=m;
    for(int a=0;a<=m;a++){
        // cerr<<a<<" "<<max(a,(n-k-2*a+1)/2)<<"\n";
        ans=min(ans,max(a,(m-k-2*a+1)/2));
    }
    printf("%d\n",ans+1);
}
int sz[MAXN],dep[MAXN],mxdep[MAXN];
int fa[MAXN][21];
int dp[MAXN1][MAXN1],tmpdp[MAXN1];
void dfs(int u){
    for(int i=1;i<=20;i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    sz[u]=1;
    dep[u]=dep[fa[u][0]]+1;
    mxdep[u]=dep[u];
    dp[u][0]=1e9;
    dp[u][1]=0;
    for(int i=2;i<=n;i++){
        dp[u][i]=1e9;
    }
    for(int v:G[u]){
        if(v==fa[u][0]){
            continue;
        }
        fa[v][0]=u;
        dfs(v);
        for(int j=1;j<=sz[u];j++){
            tmpdp[j]=dp[u][j];
            dp[u][j]=max(dp[u][j],mxdep[v]-dep[u]);
            // cerr<<j<<" "<<dp[u][j]<<" "<<tmpdp[j]<<"\n";
        }
        for(int j=1;j<=sz[u];j++){
            for(int l=1;l<=sz[v];l++){
                dp[u][j+l]=min(dp[u][j+l],tmpdp[j]+dp[v][l]);
            }
        }
        sz[u]+=sz[v];
        mxdep[u]=max(mxdep[u],mxdep[v]);
    }
    // for(int i=0;i<=sz[u];i++){
    //     cerr<<"dp["<<u<<"]["<<i<<"]:"<<dp[u][i]<<"\n";
    // }
}
int query(int u,int v){
    // cerr<<"query:"<<u<<" "<<v<<"\n";
    if(dep[u]<dep[v]){
        swap(u,v);
    }
    for(int i=20;i>=0;i--){
        if(dep[fa[u][i]]>=dep[v]){
            u=fa[u][i];
        }
    }
    // cerr<<"qqqqqq:"<<u<<" "<<v<<"\n";
    if(u==v){
        return u;
    }
    for(int i=20;i>=0;i--){
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i];
            v=fa[v][i];
        }
    }
    // cerr<<"uuuuurey:"<<u<<" "<<v<<"\n";
    return fa[u][0];
}
int dfs1(int u,int faa){
    int ret=0;
    for(int v:G[u]){
        if(v==faa){
            continue;
        }
        ret=max(ret,dfs1(v,u));
    }
    ret++;
    return ret;
}
void solve(int tcid){
    ans=1e9;
    int u,v;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        G[i].clear();
    }
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(k==n){
        printf("0\n");
        return;
    }
    if(tcid>=13&&tcid<=14){
        solve1314();
        return;
    }
    int rt=0,tmprtlen=1e9;
    for(int i=1;i<=n;i++){
        int tmp=dfs1(i,0);
        if(tmprtlen>tmp){
            rt=i;
            tmprtlen=tmp;
        }
    }
    fa[rt][0]=0;
    dfs(rt);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int tmpelse=0;
            for(int k=1;k<=n;k++){
                int tmp=1e9;
                int lca=query(i,k);
                // cerr<<i<<" "<<j<<" "<<k<<" "<<lca<<"\n";
                if(lca==i){
                    continue;
                }
                tmp=min(tmp,dep[i]+dep[k]-2*dep[lca]);

                lca=query(j,k);
                // cerr<<i<<" "<<j<<" "<<k<<" "<<lca<<"\n";
                if(lca==j){
                    continue;
                }
                tmp=min(tmp,dep[j]+dep[k]-2*dep[lca]);

                tmpelse=max(tmpelse,tmp);
            }
            int tmpans=1e9;
            for(int k1=1;k1<k;k1++){
                tmpans=min(tmpans,max(dp[i][k1],dp[j][k-k1]));
            }
            // cerr<<"!@#"<<i<<" "<<j<<" "<<tmpelse<<" "<<tmpans<<"\n";
            ans=min(ans,max(tmpans,tmpelse));
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    scanf("%d %d",&c,&T);
    while(T--){
        solve(c);
    }
    return 0;
}