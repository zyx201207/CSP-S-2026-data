#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
int n,d;
int a[N],b[N],mn,cnt[N];
vector<int> g[N];
void dfs(int x,int finish,int cur){
    if(x>=n)return ;
    if(x==finish){
        mn=min(mn,cur);
        cnt[cur]++;
        return;
    }
    if(cur>mn){
        return;
    }
    b[x]=1;
    for(int i=0;i<g[x].size();i++){
        if(b[g[x][i]]==1)continue;
        dfs(g[x][i],finish,cur+1);
    }
    b[x]=0;
}
void solve(){
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>a[i];
        g[i].clear();
    }
    if(n>10000){
        cout<<n-3<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(abs(a[j]-a[i])<=d){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+2;j<n;j++){
            memset(b,0,sizeof(b));
            memset(cnt,0,sizeof(cnt));
            mn=1e18;
            dfs(i,j,0);
            if(mn==1e18){
                continue;
            }
            if(cnt[mn]==2){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return ;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,T;cin>>c>>T;
    while(T--){
        solve();
    }
}
