#include<bits/stdc++.h>
using namespace std;
long long x[2000001],res=0,dis[2000001];
vector<pair<long long,long long>>e[2000001];
bool vis[2000001];
map<pair<long long,long long>,long long>mp;
void dij(long long x){
    memset(dis,0x3f,sizeof(dis));
    priority_queue<pair<long long,long long>>q;
    q.push({0,x});
    dis[x]=0;
    while(!q.empty()){
        long long y=q.top().second;
        q.pop();
        if(vis[y])continue;
        vis[y]=1;
        for(pair<long long,long long> i:e[y]){
            long long v=i.first,w=i.second;
            if(dis[v]>=dis[y]+w){
                dis[v]=dis[y]+w;
                if(dis[v]==dis[y]+w){
                    ++mp[{y,v}];++mp[{v,y}];
                }
                else{
                    mp[{y,v}]=mp[{v,y}]=1;
                }
                q.push({-dis[v],v});
            }
        }
    }
}
void work(){
    long long n,d;
    cin>>n>>d;
    for(long long i=1;i<=n;i++){
        cin>>x[i];
    }
    long long l=1;
    for(long long r=1;r<=n;r++){
        while(x[r]-x[l]>d)l++;
        for(long long i=l;i<=r;i++){
            e[r].push_back({i,1});
            e[i].push_back({r,1});
        }
    }
    res=0;
    for(long long i=1;i<=n;i++){
        dij(i);
        for(long long j=i+1;j<=n;j++){
            res+=(long long)(mp[{i,j}]==2);
        }
        mp.clear();
        memset(vis,0,sizeof(vis));
    }
    cout<<res<<'\n';
}
int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    long long c,t;
    cin>>c>>t;
    while(t--){
        work();
    }

    return 0;

}
