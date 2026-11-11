#include<bits/stdc++.h>
using namespace std;
long long aa[1004][1004];
long long w[2000004];
long long c,n,m,d,q;
long long v[2004][2004];
void subtack(){
    memset(aa,0x3f,sizeof(aa));
    for(int i=1;i<=n;i++){
        long long tt,u,v,t1,t2;
        cin>>tt>>u>>t1>>v>>t2;
        aa[u][v]=min(aa[u][v],t1+t2);
        aa[v][u]=min(aa[v][u],t2+t1);
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                aa[i][j]=min(aa[i][j],aa[i][k]+aa[k][j]);
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<aa[u][v]+w[u]+w[v]<<"\n";
    }
}
long long dis[2004];
struct an{
    long long d,u;
    bool operator<(const an& t)const{
        return d>t.d;
    }
};
vector<an> a[2000004];
bool beenQ[2004];
long long get(int u,int vv){
    memset(dis,0x3f,sizeof(dis));
    memset(beenQ,0,sizeof(beenQ));
    dis[u]=0;
    priority_queue<an> Q;
    Q.push({0,u});
    while(Q.size()){
        long long d=Q.top().d,x=Q.top().u;
        Q.pop();
        if(beenQ[x]){
            continue;
        }
        beenQ[1];
        for(auto i:a[x]){
            if(dis[i.u]>dis[x]+i.d){
                dis[i.u]=dis[x]+i.d;
                if(!beenQ[i.u]){
                    Q.push({dis[i.u],i.u});
                }
            }
        }
    }
    return dis[vv];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    if(c>=7&&c<=11){
        subtack();
        return 0;
    }
    for(int ii=1;ii<=n;ii++){
        int k;
        cin>>k;
        vector<an> cc;
        for(int i=1;i<=k;i++){
            long long u,t;
            cin>>u>>t;
            for(auto j:cc){
                a[j.u].push_back({t+j.d  ,  u});
                a[u].push_back({  t+j.d  ,j.u});
            }
            cc.push_back({t,u});
        }
    }
//    for(int i=1;i<=10;i++){
//            cout<<i<<':';
//        for(auto j:a[i]){
//            cout<<j.u<<' ';
//        }
//        cout<<endl;
//    }
    while(q--){
        long long u,v;
        cin>>u>>v;
        cout<<get(u,v)+w[u]+w[v]<<"\n";
    }
    return 0;
}
