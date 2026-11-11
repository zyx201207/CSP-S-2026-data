#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5*1e5+10;

int C,n,m,d,q;
int w[N];
int a[1010][1010],t[1010][1010];
int k[1010];
int stx[N],edy[N];
int dis[N];

vector<pair<int,int>> g1[N];

void dij1(int st,int ed){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,st});
    dis[st]=0;
    while(!q.empty()){
        int step=q.top().first;
        int u=q.top().second;
        q.pop();
        for(auto v:g1[u]){
            if(dis[u]+v.second<dis[v.first]){
                dis[v.first]=dis[u]+v.second;
                q.push({dis[v.first],v.first});
            }
        }
    }
    cout<<dis[ed]<<"\n";
}

void solve1(){
    for(int i=1;i<=n;i++){
        if(k[i]==1)continue;
        g1[a[i][1]].push_back({a[i][2] , t[i][1]+t[i][2]});
        g1[a[i][2]].push_back({a[i][1] , t[i][1]+t[i][2]});
    }

    for(int i=1;i<=q;i++){
        dij1(stx[i],edy[i]);
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof dis);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
//        cin>>k[i];
        scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];j++){
//            cin>>a[i][j]>>t[i][j];
            scanf("%lld%lld",&a[i][j],&t[i][j]);
        }
    }
//    if(C>=7&&C<=11){
//        solve1();
//    }
    for(int i=1;i<=q;i++){
        cin>>stx[i]>>edy[i];
    }
    if(C>=7&&C<=11)solve1();
    return 0;
}

/*
0 4 4 20 1
4 1 9 2
2 1 5 2 7
2 2 3 3 5
2 3 4 4 10
2 2 3 4 6
1 4*/
