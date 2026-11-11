#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k[214514],w[114514],dist[114514],f[114514];
struct node{
    long long a,b;
};
vector<node> lxh[214514];
void SPFA(long long fir){
    memset(dist,0x3f,sizeof(dist));
    priority_queue<long long,vector<long long>,greater<long long>> q;
    dist[fir]=0;
    q.push(fir);
    f[fir]=1;
    while(!q.empty()){
        long long u=q.top();
        q.pop();
        f[u]=0;
        for(node i:lxh[u]){
            if(i.b+dist[u]<dist[i.a]){
                dist[i.a]=dist[u]+i.b;
                if(!f[i.a]){
                    q.push(i.a);
                    f[i.a]=1;
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++){
        cin>>w[i];
        lxh[i].push_back({i+m,w[i]});
        lxh[i+m].push_back({i,w[i]});
    }
    for(long long i=1;i<=n;i++){
        cin>>k[i];
        for(long long j=1;j<=k[i];j++){
            long long a,t;
            cin>>a>>t;
            lxh[i+m].push_back({a+2*m,t});
            lxh[a+2*m].push_back({i+m,t});
        }
    }
    for(long long i=1;i<=q;i++){
        long long l,r;
        cin>>l>>r;
        SPFA(l);
        cout<<dist[r]<<endl;
    }
    return 0;
}