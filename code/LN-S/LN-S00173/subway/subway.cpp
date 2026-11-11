#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10000;
vector<pair<int,long long>>e[N];
long long c,n,m,dd,q,ww[N],k,aa[N],tt[N];
long long d[N];
void dij(long long s){
    for(int i=1;i<=m*(n+1);i++)d[i]=4e18;
    d[s]=0;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
    q.push(make_pair(0,s));
    while(!q.empty()){
        long long dis=q.top().first;
        int u=q.top().second;
        q.pop();
        if(dis>d[u])continue;
        for(auto pq : e[u]){
            int v=pq.first;
            long long w=pq.second;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                q.push(make_pair(d[v],v));
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>dd>>q;
    for(int i=1;i<=m;i++)cin>>ww[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>aa[j]>>tt[j];
            e[aa[j]].push_back(make_pair(aa[j]+i*m,tt[j]));
            e[aa[j]+i*m].push_back(make_pair(aa[j],0));
            for(int jj=1;jj<j;jj++){
                e[aa[jj]+i*m].push_back(make_pair(aa[j]+i*m,tt[j]));
                e[aa[j]+i*m].push_back(make_pair(aa[jj]+i*m,tt[jj]));
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;cin>>x>>y;
        dij(x);
        cout<<d[y]+ww[x]+ww[y]<<"\n";
    }
    return 0;
}
