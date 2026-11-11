#include<bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=2e6+10;
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
struct node{
    int to,w;
    node()=default;
    node(int t,int w):to(t),w(w){}
    bool operator<(const node&o)const{
        return w>o.w;
    }
};
vector<node>gra[maxn];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int c=read(),n=read(),m=read(),d=read(),q=read();
    vector<int>w(m+1);
    for(int i=1;i<=m;++i){
        w[i]=read();
    }
    vector<vector<int>>a(n+1),t(n+1);
    vector<vector<int>>G(n+1,vector<int>(n+1,1e18));
    for(int i=1;i<=n;++i){
        G[i][i]=0;
    }
    for(int i=1;i<=n;++i){
        int u=i+m;
        int k=read();
        a[i].resize(k+1),t[i].resize(k+1);
        for(int j=1;j<=k;++j){
            a[i][j]=read();
            t[i][j]=read();
            int v=a[i][j],w=t[i][j];
            gra[u].emplace_back(v,w);
            gra[v].emplace_back(u,w);
        }
    }
    for(int i=1;i<=n;++i){
        int u=i+m;
        // cerr<<"------\n";
        // cerr<<"u="<<u<"\n";
        for(auto[v,w]:gra[u]){
            // cerr<<"v="<<v<<" w="<<w<"\n";
            for(auto[t,d]:gra[v]){
                int z=w+d;
                G[i][t-m]=min(G[i][t-m],z);
            }
        }
    }
    // cerr<<"zzr\n";
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
            }
        }
    }
    auto dj=[&](int s){
        vector<int>dis(n+m+1,1e18);
        dis[s]=0;
        priority_queue<node>q;
        q.emplace(s,0);
        while(!q.empty()){
            auto[u,d]=q.top();
            q.pop();
            if(dis[u]<d)continue;
            for(auto[v,w]:gra[u]){
                if(dis[v]>d+w){
                    dis[v]=d+w;
                    q.emplace(v,d+w);
                }
            }
        }
        return dis;
    };
    vector<int>res(m+1);
    while(q--){
        int x=read(),y=read();
        int z=1e18;
        for(auto[u,w]:gra[x]){
            for(auto[v,d]:gra[y]){
                z=min(z,w+d+G[u-m][v-m]);
            }
        }
        cout<<z+w[x]+w[y]<<"\n";
    }
    return 0;
}