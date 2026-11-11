#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int c,T,n,k,mixn;
struct Node{
    int v,w;
    bool operator<(const Node&x) const{
        return w>x.w;
    }
};
priority_queue<Node> q;
Node u;
vector<Node> G[N];
int dis[N];
bool vis[N];
void f(int x,int y){
    q.push({x,0});
    dis[x]=0;
    while(!q.empty()){
        u=q.top();
        q.pop();
        if(vis[u.v]){
            continue;
        }
        if(u.v==y){
            break;
        }
        vis[u.v]=1;
        for(auto i:G[u.v]){
            int iv=i.v,iw=i.w;
            if(dis[iv]>dis[u.v]+iw){
                dis[iv]=dis[u.v]+iw;
                q.push({iv,dis[iv]});
            }
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        mixn=0x3f3f3f3f;
        for(int i=1;i<n;++i){
            int u,v;
            cin>>u>>v;
            G[u].push_back({v,1});
            G[v].push_back({u,1});
        }
        for(int i=1;i<=n;++i){
            while(!q.empty()) q.pop();
            for(int j=i;j<=n;++j){
                memset(vis,false,sizeof(vis));
                memset(dis,0x3f3f3f3f,sizeof(dis));
                f(i,j);
                mixn=min(mixn,dis[j]);
            }
        }
        cout<<mixn<<endl;
    }
    return 0;
}
