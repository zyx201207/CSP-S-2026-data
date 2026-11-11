#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5,inf=LLONG_MAX;
int n,d;
int x[N];
int dis[N],f[N];
queue<int> q;
int bfs(int s,int t){
    for(int i=s;i<=t;i++){
        dis[i]=inf;f[i]=0;
    }
    while(!q.empty())q.pop();
    q.push(s);dis[s]=0;f[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        if(u==t)continue;
        for(int v=u+1;v<=t;v++){
            if(x[v]-x[u]<=d){
                if(dis[v]>dis[u]+1){
                    dis[v]=dis[u]+1;
                    f[v]=f[u];
                    q.push(v);
                }else if(dis[v]==dis[u]+1){
                    f[v]+=f[u];
                }
            }
        }
    }
    return f[t];
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    // for(int i=1;i<=n;i++){
    //     cout<<i<<' ';
    //     if(f[i]==0)bfs(i,n);
    // }cout<<'\n';
    //bfs(1,n);
    //for(int i=1;i<=n;i++)cout<<f[i]<<' ';cout<<'\n';
    int ans=0;
    for(int s=1;s<=n;s++){
        for(int t=s+1;t<=n;t++){
            int res=bfs(s,t);
            if(res==2)ans++;
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int C,T;cin>>C>>T;
    while(T--)solve();
    return 0;
}