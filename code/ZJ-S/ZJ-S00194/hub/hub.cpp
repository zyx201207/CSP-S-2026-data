#include<bits/stdc++.h>
using namespace std;
#define int long long 
using ii=__int128;
constexpr int maxn=1e6+10;
inline int read(){
    int f=0,num=0,c=cin.rdbuf()->sbumpc();
    while(!isdigit(c)){
        if(c=='-')f=1;
        c=cin.rdbuf()->sbumpc();
    }
    while(isdigit(c)){
        num=(num<<1)+(num<<3)+(c^48);
        c=cin.rdbuf()->sbumpc();
    }
    return f?-num:num;
}
vector<int>gra[maxn];
int siz[maxn];
bitset<maxn>vis;
struct node{
    int len,rt;
    node()=default;
    node(int l,int r):len(l),rt(r){}
    bool operator<(const node&o)const{
        return len>o.len;
    }
};
int pre[maxn],dep[maxn],mxd[maxn];
vector<int>arr;
void dfs(int x,int p){
    dep[x]=dep[p]+1;
    pre[x]=pre[p];
    arr.emplace_back(x);
    for(int v:gra[x]){
        if(v==p)continue;
        if(vis[v])continue;
        dfs(v,x);
    }
}
void dfs2(int x,int p){
    mxd[x]=dep[x];
    for(int v:gra[x]){
        if(vis[v]||v==p)continue;
        dep[v]=mxd[v]=dep[x]+1;
        dfs2(v,x);
        mxd[x]=max(mxd[x],mxd[v]);
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int c=read(),t=read();
    while(t--){
        int n=read(),k=read();
        for(int i=1;i<=n;++i){
            gra[i].clear();
        }
        vis.reset();
        for(int i=1;i<n;++i){
            int u=read(),v=read();
            gra[u].emplace_back(v);
            gra[v].emplace_back(u);
        }
        if(n<=10){
            int ans=1e18;
            vector<vector<int>>G(n+1,vector<int>(n+1,1e18));
            for(int i=1;i<=n;++i){
                G[i][i]=0;
                for(int v:gra[i]){
                    G[i][v]=1;
                }
            }
            for(int k=1;k<=n;++k){
                for(int i=1;i<=n;++i){
                    for(int j=1;j<=n;++j){
                        G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
                    }
                }
            }
            for(int o=0;o<=1ll<<n;++o){
                if(__builtin_popcountll(o)!=k)continue;
                {
                    int cc=0;
                    vector<bool>vis(n+1);
                    for(int i=1;i<=n;++i){
                        if(o>>(i-1)&1){
                            if(vis[i])continue;
                            queue<int>q;
                            ++cc;
                            q.emplace(i);
                            while(!q.empty()){
                                int u=q.front();
                                q.pop();
                                for(int v:gra[u]){
                                    if((o>>(v-1)&1)^1)continue;
                                    if(vis[v])continue;
                                    vis[v]=1;
                                    q.emplace(v);
                                }
                            }
                        }
                    }
                    if(cc>2)continue;
                }
                
                
                int tmp=0;
                for(int i=1;i<=n;++i){
                    int d=1e18;
                    for(int j=1;j<=n;++j){
                        if(o>>(j-1)&1){
                            d=min(d,G[i][j]);
                        }
                    }
                    tmp=max(tmp,d);
                }
                ans=min(ans,tmp);
            }
            cout<<ans<<"\n";
            continue;
        }
        if(k==2){
            dfs(1,0);
            int rt=0;
            for(int i=1;i<=n;++i){
                if(dep[i]>dep[rt]){
                    rt=i;
                }
            }
            dfs(rt,0);
            vector<int>chain;
            {
                int u=0;
                for(int i=1;i<=n;++i){
                    if(dep[i]>dep[u]){
                        u=i;
                    }
                }
                while(u){
                    chain.emplace_back(u);
                    vis[u]=1;
                    u=pre[u];
                }
            }
            for(int u:chain){
                dep[u]=0;
                dfs2(u,0);
            }
            int ans=0;
            for(int i=0;i<chain.size();++i){
                ans=max(ans,mxd[i]);
            }
            cout<<ans<<"\n";
            continue;
        }
        cout<<n/k<<"\n";
    }
    return 0;
}