#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mkp make_pair

const int inf=0x3f3f3f3f;
const int N=2e6+10;
const int M=510;
const int K=5e5+10;
vector<pair<int,ll>>g[N];
int hall[K];
ll dis[N];
int tot;
struct node{
    int u;
    ll d;
    friend bool operator<(node a,node b){
        return a.d>b.d;
    }
};

ll dij(int x,int y){
    for(int i=1;i<=tot;i++)dis[i]=inf;
    priority_queue<node>q;
    q.push({x,0});
    dis[x]=0;
    while(!q.empty()){
        node f=q.top();
        int u=f.u,d=f.d;
        q.pop();
        if(d>dis[u])continue;
        for(auto e:g[u]){
            int v=e.first,w=e.second;
            if(dis[u]+w<dis[v])dis[v]=dis[u]+w,q.push({v,dis[v]});
        }
    }
    return dis[y];
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    tot=m;
    for(int i=1;i<=m;i++){
        int w;
        cin>>w;
        hall[i]=++tot;
        g[i].push_back(mkp(tot,w));
        g[tot].push_back(mkp(i,w));
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int lst=0;
        for(int j=1;j<=k;j++){
            int a,w;
            cin>>a>>w;
            tot++;
            if(lst!=0){
                g[lst].push_back(mkp(tot,0));
                g[tot].push_back(mkp(lst,0));
            }
            lst=tot;
            g[hall[a]].push_back(mkp(tot,w));
            g[tot].push_back(mkp(hall[a],w));
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<dij(x,y)<<'\n';
    }
    return 0;
}
