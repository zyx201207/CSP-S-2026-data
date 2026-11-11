#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5005;
int c,t,n,dis[M][M],sum[M][M],ans;
ll x[M],d;
bool vis[M];
struct node{
    int to;
    ll w;
    bool operator < (const node& other) const{
        return w > other.w;
    }
};
vector<node> v[M];
priority_queue<node> q;
void diji(ll u){
    for(int i=1;i<=n;i++){
        dis[u][i]=INT_MAX;
        vis[i]=0;
        sum[u][i]=0;
    }
    dis[u][u]=0;
    q.push({u,0});
    while(!q.empty()){
        int x=q.top().to;
        q.pop();
        if(vis[x]==1)continue;
        vis[x]=1;
        for(int i=0;i<v[x].size();i++){
            int to=v[x][i].to;
            ll w=v[x][i].w;
            if(dis[u][to]==dis[u][x]+w){
                sum[u][to]++;
            }
            if(dis[u][to]>dis[u][x]+w){
                dis[u][to]=dis[u][x]+w;
                sum[u][to]=1;
                q.push({to,dis[u][to]});
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            while(!v[i].empty()){
                v[i].pop_back();
            }
        }
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[i]<0){
                    if(x[j]<=d+x[i]){
                        v[i].push_back({j,1});
                    }
                }
                else{
                    if(abs(x[j]-x[i])<=d){
                        v[i].push_back({j,1});
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            diji(i);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(sum[i][j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
