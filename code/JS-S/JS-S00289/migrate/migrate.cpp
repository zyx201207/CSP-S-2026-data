#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=5005,inf=1e9+7;
int c,t,n,cnt[N][N],sz[N][N];
ll d,x[N],ans;
vector<int>adj[N];
void dfs(int fir,int u,int len){
    if(len<sz[fir][u]){
        sz[fir][u]=len;
        cnt[fir][u]=1;
    }else if(len==sz[fir][u]){
        cnt[fir][u]++;
    }
    for(auto v:adj[u]){
        if(len+1>sz[fir][v])continue;
        dfs(fir,v,len+1);
    }
}
void solve(){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cnt[i][j]=0;
            sz[i][j]=inf;
        }
        adj[i].clear();
    }
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(x[j]-x[i]<=d){
                adj[i].push_back(j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        dfs(i,i,0);
    }
    ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(cnt[i][j]==2){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        if(n<=N)solve();
    }
    return 0;
}
