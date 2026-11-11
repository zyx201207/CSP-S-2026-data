#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int inf=0x3f3f3f3f;

const int N=511;
const int M=500011;

int c,n,m,d,q,wi[N],k[N],a[N][M],t[N][M];
int x[100011],y[100011];
int dis[N][M];

/*
    A

    edge number -> n

    edge weight -> t[i][1] +t[i][2]


*/

struct node{
    int v,w;
};

vector<node> edge[N];

// I should realize the dangerous when ccf didn't put any of the shortest path of graph in the morning.

void dij(int s,int t){
    for(auto [v,w]:edge[s]){
        dis+=w;
        dij(v,t);
    }
    cout<<dis<<"\n";
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>wi[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
    }
    for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
    if(c==7||c==8||c==9||c==10||c==11){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                int u=a[i][1],v=a[i][2],w=t[i][2]+t[i][1];
                edge[u].push_back({v,w});
                edge[v].push_back({u,w});
            }
        }
        for(int i=1;i<=q;i++) dij(x[i],y[i]);
    }
    if(c==1||c==2||c===3){
        //m<=8, n<=3
    }
}
