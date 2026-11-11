#include<bits/stdc++.h>
using namespace std;
const int N=505005*2;
int c,n,m,d,q;
int a[N];
struct Node{
    int v,w;
    bool operator<(const Node &x) const {
        return w>x.w;
    }
};
bool cmp(Node x,Node y){
    if(x.w!=y.w) return x.w<y.w;
    return false;
}
vector<Node> G[N];
priority_queue<Node> Q;
Node u;
bool vis[N];
int dis[N],mixn=0x3f3f3f3f;
int f(int st,int e){
    Q.push({st,0});
    mixn=0x3f3f3f3f;
    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[st]=0;
    memset(vis,false,sizeof(vis));
    while(!Q.empty()){
        u=Q.top();
        Q.pop();
       // cout<<u.v<<"     ";
        if(u.w>=mixn){
            continue;
        }
        if(u.v==e){
            mixn=min(mixn,u.w);
            continue;
        }
        if(vis[u.v]){
            continue;
        }
        vis[u.v]=1;
        for(auto i:G[u.v]){
            int iv=i.v;
            int iw=i.w;
            if(dis[iv]>dis[u.v]+iw){
                dis[iv]=dis[u.v]+iw;
                Q.push({iv,dis[iv]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>a[i];
        G[i].push_back({i+500,a[i]});
        G[i+500].push_back({i,a[i]});
    }
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        for(int j=1;j<=k;++j){
            int v,w;
            cin>>v>>w;
            G[v].push_back({i+500+m,w});
            G[i+500+m].push_back({v,w});
        }
    }
    for(int i=1;i<=n+500+m;++i){
        sort(G[i].begin(),G[i].end(),cmp);
    }
    for(int i=1;i<=q;++i){
        int s,e;
        cin>>s>>e;
        f(s+500,e+500);
        cout<<mixn<<endl;
    }/*
    for(int i=1;i<=m;++i){
            cout<<i<<":";
        for(auto j:G[i]){
            cout<<j.v<<" ";
        }
        cout<<endl;
    }*/
    return 0;
}
