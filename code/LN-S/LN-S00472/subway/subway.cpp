#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>>e[500505];
bool vis[500505];
long long d[500505];
long long a[500505];
void dj(long long s){

    memset(d,0x3f3f3f3f3f3f3f,sizeof(d));
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
    q.push({s,0});
    d[s]=0;
    long long u=s;
    while(!q.empty()){
        u=q.top().first;
        q.pop();
        for(auto [v,w]:e[u]){
            if(vis[u])continue;
            if(d[v]+w<d[u]){
                d[u]=d[v]+w;
            }
            q.push({v,w});
        }
        vis[u]=1;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,o,p;
    cin>>c>>n>>m>>o>>p;
    for(long long i=1;i<=m;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        long long k;
        cin>>k;
        for(long long j=1;j<=k;j++){
            long long x;
            cin>>x;
            long long y;
            cin>>y;
            e[x].push_back({500000+i,y});
            e[500000+i].push_back({x,y});
        }
    }
    while(p--){
        memset(vis,0,sizeof(vis));
        long long l,r;
        cin>>l>>r;
        dj(l);
        cout<<a[l]+d[r]+a[r]<<'\n';
    }
    return 0;
}
