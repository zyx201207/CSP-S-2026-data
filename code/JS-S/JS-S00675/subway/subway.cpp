#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct nod{
    int v,w;
};
bool operator<(nod a,nod b){
    return a.w>b.w;
}
priority_queue<nod> pq;
vector<nod> ve[N];
int dis[N];
int vis[N];
int w[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
             int v,w;
            cin>>v>>w;
            ve[m+i].push_back({v,w});
            ve[v].push_back({m+i,w});
        }
    }
    while(q--){
        while(!pq.empty()){
            pq.pop();
        }
        for(int i=0;i<=n+m+1;i++){
            dis[i]=INT_MAX;
        }
        for(int i=0;i<=n+m+1;i++){
        vis[i]=0;
        }
        int l,r;
        cin>>l>>r;
        dis[l]=0;
        pq.push({l,0});
        while(!pq.empty()){
            nod h=pq.top();
            pq.pop();
            if(vis[h.v]) continue;
            vis[h.v]=1;
            for(nod x:ve[h.v]){
                if(dis[x.v]>dis[h.v]+x.w){
                    dis[x.v]=dis[h.v]+x.w;
                    pq.push({x.v,dis[x.v]});
                }
            }
        }
        cout<<dis[r]+w[l]+w[r]<<'\n';
    }

}
