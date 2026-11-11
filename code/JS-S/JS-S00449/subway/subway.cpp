#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,n,m,d,q;
vector<int>w;
const int N=200005,inf=INT_MAX-1;
struct node{
    int y,v;
    node(int _y,int _v){
        y=_y;
        v=_v;
    }
};
vector<node>edge[N];
int dijistra(int s,int t){
    int dist[m+n+5];
    fill(dist,dist+m+n+6,inf);
    dist[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,s});
    while(!pq.empty()){
        int d=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(d!=dist[u])continue;
        for(auto p:edge[u]){
            if(dist[p.y]>dist[u]+p.v){
                dist[p.y]=dist[u]+p.v;
                pq.push({dist[p.y],p.y});
            }
        }
    }
    return dist[t]!=inf ? dist[t]:-1;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    w.push_back(0);
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        w.push_back(x);
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int s=1;s<=k;s++){
            int a,t;
            cin>>a>>t;
            edge[a].push_back(node(i+m,t));
            edge[i+m].push_back(node(a,t));
        }
    }
    for(int i=1;i<=q;i++){
        int s,t;
        cin>>s>>t;
        cout<<dijistra(s,t)+w[s]+w[t]<<endl;
    }
    return 0;
}
