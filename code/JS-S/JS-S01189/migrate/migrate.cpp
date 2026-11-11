#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[200005];
vector<int>g[200005];
long long mn,cnt2;
void dfs(int i,int j,int cnt){
    //cout<<i<<' '<<j<<' '<<cnt<<endl;
    if(i==j){
        if(cnt==mn)cnt2++;
        else if(cnt<mn)cnt2=1,mn=cnt;
        return;
    }
    for(int u:g[i]){
        if(x[u]-x[i]<=d)dfs(u,j,cnt+1);
    }
}
bool check(int i,int j){
    cnt2=0;mn=4e18;
    dfs(i,j,1);
    return cnt2==2;
}
void solve(){
    int ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            g[i].push_back(j);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(check(i,j))ans++;
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--)solve();
}
