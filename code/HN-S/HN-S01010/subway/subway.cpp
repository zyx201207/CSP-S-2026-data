#include<bits/stdc++.h>
using namespace std;
using Pii=pair<long long,int>;
const int kMaxM=5e5+5,kMaxN=510,kMaxM2=1510;
int c,n,m,d,q;
long long w[kMaxM],dis[kMaxM2][kMaxM2];
vector<Pii> s[kMaxN+kMaxM];
priority_queue<Pii,vector<Pii>,greater<Pii>> pq;
void F(int sx){
    pq.push({0,sx});
    while(!pq.empty()){
        Pii p=pq.top();
        pq.pop();
        if(dis[sx][p.second]<=p.first) continue;
        dis[sx][p.second]=p.first;
        for(Pii i:s[p.second]){
            pq.push({p.first+i.first,i.second});
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(long long j=1,x,t;j<=k;j++){
            cin>>x>>t;
            s[i+m].push_back({t,x});
            s[x].push_back({t,i+m});
        }
    }
    fill(dis[0],dis[n+m+2],1e18);
    for(int i=1;i<=m;i++){
        F(i);
    }
    for(int i=1,x,y;i<=q;i++){
        cin>>x>>y;
        cout<<dis[x][y]+w[x]+w[y]<<'\n';
    }
    return 0;
}