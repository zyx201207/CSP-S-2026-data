#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
vector<int> x[maxn];
int k[maxn],t[maxn];
int di(int e){
    int u=e;
    priority_queue<int,vector<make_pair<> >,greater<> > pq;
    for(int i=0;i<=x[u].size();i++){
        if(i!=0){
            int v=x[u][i].first();
            t[v]+=x[u][i].second();
        }
        pq.push(x[u][i]);
    }
    while(pq.empty()){
        int v=pq.top().first;
        int w=pq.top().second;
        pq.pop();
        if(t[v]==w)continue;
        else if(t[e]+w<t[v])t[v]=t[e]+w;
        u=v;
        for(int i=0;i<sizeof(u);i++){
            pq.push(x[e][i]);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>k[i];

    }
    for(int i=1;i<=n;i++){
        int u=0;
        int r;cin>>r;
        for(int j=1;j<=r;j++){
            int v,w;cin>>v>>w;
            x[u].push_back({v,w});
            u=v;
        }
    }
    for(int i=1;i<=q;i++){
        memset(t,INT_MAX,sizeof(t));
        int g,w;cin>>g>>w;
        t[g]=0;
        di(g);
        cout<<t[w]+k[g]+k[w]<<'\n';
    }
    return 0;
}
