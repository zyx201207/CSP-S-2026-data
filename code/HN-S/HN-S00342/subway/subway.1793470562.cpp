#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+505;
const int M=505;
const ll INF=1e18;


ll qr(){
    char ch=getchar();ll x=0,f=1;
    while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=(x*10)+ch-48;ch=getchar();}
    return f*x;
}

struct Node{
    ll v,w;
    bool operator >(const Node _)const{
        return w>_.w;
    }
};

bool cmp(Node a,Node b){
    return a.w<b.w;
}

vector<Node> graph[N];
ll stationPrice[M];

vector<ll> dij(int start,int n){
    vector<ll> dist(n+1,INF);
    vector<bool> vis(n+1,false);
    priority_queue<Node,vector<Node>,greater<Node>> pq;

    dist[start]=0;
    vis[start]=1;
    pq.push({start,0});
    while(!pq.empty()){
        auto it=pq.top();pq.pop();

        for(auto it1:graph[it.v]){
            if(!vis[it1.v]){
                if(dist[it1.v]>dist[it.v]+it1.w){
                    dist[it1.v]=dist[it.v]+it1.w;
                    vis[it1.v]=1;
                    pq.push({it1.v,dist[it1.v]});
                }
            }
        }
    }

    return dist;
}


int main(){
    freopen("C:/subway6.in","r",stdin);
    freopen("C:/subway.out","w",stdout);

    int c=qr(),n=qr(),m=qr(),d=qr(),q=qr();
    for(int i=1;i<=m;i++) stationPrice[i]=qr();
    for(int i=1;i<=n;i++){
        int passNum=qr();
        for(int j=1;j<=passNum;j++){//i:lineNum,a:stationNum
            int a=qr(),t=qr();
            graph[a].push_back({i+m,t});
            graph[i+m].push_back({a,t});
        }
    }
    vector<vector<ll>> tmp(m+1,vector<ll>());

    for(int i=0;i<q;i++){
        int u=qr(),v=qr(),w=stationPrice[u]+stationPrice[v];
        if(!tmp[u].empty()) printf("%lld\n",tmp[u][v]+w);
        else {
            tmp[u]=dij(u,n+m);
            printf("%lld\n",tmp[u][v]+w);
        }
    }
    return 0;

}
