#include<bits/stdc++.h>
using namespace std;
const int N=15;
int C,T,n,k,ans;
int fa[N][5],h[N];
vector<int>e[N];
bool had[N];
void trv(int u,int fth){
    fa[u][0]=fth;
    for(int i=1;i<5;++i)fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int v:e[u]){
        if(v==fth)continue;
        h[v]=h[u]+1;
        trv(v,u);
    }
}
int lca(int u,int v){
    if(h[u]<h[v])swap(u,v);
    for(int i=4;i>=0;--i)if(fa[u][i]&&h[fa[u][i]]>=h[v])u=fa[u][i];
    if(u==v)return u;
    for(int i=4;i>=0;--i)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
int check(int u,int from){
    int res=1;
    for(int v:e[u]){
        if(v==from)continue;
        if(had[v])res+=check(v,u);
    }
    return res;
}
void dfs(int p,int q){
    if(q==k){
        int cnt=0,tot=0;
        for(int i=1;i<=n;++i){
            if(had[i]){
                tot+=check(i,0);
                ++cnt;
                if(cnt==2)break;
            }
        }
        if(tot!=k)return;
        int res=0;
        for(int i=1;i<=n;++i){
            if(had[i])continue;
            int dis=n;
            for(int j=1;j<=n;++j){
                if(!had[j])continue;
                dis=min(dis,h[i]+h[j]-h[lca(i,j)]*2);
                // fprintf(stderr,"(%d,%d) lca=%d dis=%d\n",i,j,lca(i,j),h[i]+h[j]-h[lca(i,j)]*2);
            }
            // fprintf(stderr,"dis(%d)=%d\n",i,dis);
            res=max(res,dis);
        }
        // fprintf(stderr,"( ");
        // for(int i=1;i<=n;++i)if(had[i])fprintf(stderr,"%d ",i);
        // fprintf(stderr,"):%d\n",res);
        ans=min(ans,res);
    }
    if(p>n)return;
    for(int i=p+1;i<=n;++i){
        had[i]=true;
        dfs(i,q+1);
        had[i]=false;
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<n;++i){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);

        }
        trv(1,0);
        // fprintf(stderr,"lca(1,2)=%d\n",lca(1,2));
        ans=n;
        dfs(0,0);
        cout<<ans<<'\n';
        for(int i=1;i<=n;++i){
            e[i].clear();
            h[i]=0;
            for(int j=0;j<5;++j)fa[i][j]=0;
        }
    }
    return 0;
}