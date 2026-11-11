#include<bits/stdc++.h>
using namespace std;

#define int long long

int C,D;
int n,m,Q;

int w[500010];
struct Edge{
    int v,w;
};
vector<Edge>e[500510];
int g[510][510];

void pre(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==j){
                continue;
            }
            g[i][j]=1e18;
        }
    }
    for(int i=1;i<=m;++i){
        for(Edge a:e[i]){
            for(Edge b:e[i]){
                int u=a.v,v=b.v;
                int wu=a.w,wv=b.w;
                g[u-m][v-m]=min(g[u-m][v-m],wu+wv);
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(g[i][j]>g[i][k]+g[k][j]){
                    g[i][j]=g[i][k]+g[k][j];
                }
            }
        }
    }
}

//O(n^2) per query?Not exactly.d<=20.O(d^2).That's adoptable.
int work(int x,int y){
    int ret=1e18;
    for(Edge e1:e[x]){
        for(Edge e2:e[y]){
            ret=min(ret,g[e1.v-m][e2.v-m]+e1.w+e2.w);
        }
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>D>>Q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    for(int i=1,k;i<=n;++i){
        cin>>k;
        for(int j=1,v,w;j<=k;++j){
            cin>>v>>w;
            e[i+m].push_back({v,w});
            e[v].push_back({i+m,w});
        }
    }
    pre();
    for(int x,y;Q--;){
        cin>>x>>y;
        cout<<work(x,y)+w[x]+w[y]<<"\n";
    }
}