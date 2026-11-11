#include <bits/stdc++.h>
using namespace std;
namespace LUCKY{

using ll = long long;
#define int long long
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rof(i,a,b) for(int i=(a);i>=(b);--i)
using PII = pair<int,int>;
#define fi first
#define se second

constexpr int N=1e6+6;

vector<int> G[N];
int dep[N];

void dfs(int u,int f){
    dep[u]=dep[f]+1;
    for(int v:G[u]){
        if(v==f) continue;
        dfs(v,u);
    }
}

int fa[N];
bool vis[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
    fa[find(x)]=fa[find(y)];
}

bool bs[N];
int dis[N];
queue<PII> Q;
int bfs(int st){
    if(vis[st]) return 0;
    memset(bs,0,sizeof(bs));
    memset(dis,0x3f,sizeof(dis));
    while(Q.size()) Q.pop();
    Q.push({0,st}); dis[st]=0;
    bs[st]=true;
    while(Q.size()){
        int u=Q.front().se,d=Q.front().fi;
        // if(vis[u]) cerr<<"!!! "<<st<<' '<<u<<' '<<d<<endl;
        if(vis[u]) return d;
        Q.pop();
        for(int v:G[u]){
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                if(bs[v]) continue;
                bs[v]=true;
                Q.push({dis[v],v});
            }
        }
    } return -1;
}

void OvO(){
    int c,t; cin>>c>>t;
    while(t--){
        int n,k; cin>>n>>k;
        For(i,1,n) G[i].clear();
        For(i,1,n-1){
            int u,v; cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(n<=10){
            const int M=(1<<n)-1;
            int ans=n;
            For(i,1,M){
                int cnt=0;
                vector<int> p;
                For(j,1,n){
                    if((i>>(j-1))&1) ++cnt,
                    p.emplace_back(j);
                } if(cnt>k) continue;
                For(i,1,n) fa[i]=i;
                For(i,1,n) vis[i]=false;
                for(int u:p){
                    vis[u]=true;
                    for(int v:G[u]){
                        merge(u,v);
                    }
                } cnt=0;
                For(i,1,n) cnt+=(find(i)==i);
                if(cnt>2) continue;
                int res=0;
                For(i,1,n){
                    res=max(res,bfs(i));
                }
                
                // cerr<<i<<endl;
                // for(int x:p) cerr<<x<<' ';
                // cerr<<endl<<' '<<res<<endl;

                ans=min(ans,res);
            }
            // cerr<<"ans: "<<endl;
            cout<<ans<<endl;
        } else cout<<(n-k)/2<<endl;
    }
}

#undef int
} using LUCKY::OvO;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	OvO(); return 0;
}

/*

g++ hub.cpp -o hub -std=c++14 -O2 -Wall -Wextra -static

*/