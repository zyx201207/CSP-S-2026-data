#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,_,n,d,ans;
int a[N],x[N],mx[N],deg[N],tdeg[N];
int mi[N],dp[N];
queue<int> q;
void solve(int l,int r){
    for(int i=l;i<=r;i++){
        for(int j=i;j<=r;j++){
            if(x[j]-x[i]>d) break;
            mx[i]=j;
        }
    }
    for(int i=r;i>=l;i--){
        for(int j=i+1;j<=mx[i];j++) tdeg[j]++;
        for(int j=i+1;j<=r;j++) deg[j]=tdeg[j];
        for(int j=i;j<=r;j++) dp[j]=0,mi[j]=1e12;
        mi[i]=0,dp[i]=1;
        while(!q.empty()) q.pop();
        for(int j=i;j<=r;j++) if(!deg[j]) q.push(j);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(dp[u]==2) ans++;
            for(int i=u+1;i<=mx[u];i++){
                int v=i;
                deg[v]--;
                if(mi[v]>mi[u]+1) mi[v]=mi[u]+1,dp[v]=dp[u];
                else if(mi[v]==mi[u]+1) dp[v]+=dp[u];
                dp[v]=min(dp[v],3ll);
                if(!deg[v]) q.push(v);
            }
        }
    }
}
void work(){
    cin>>n>>d; ans=0;
    for(int i=1;i<=n;i++) tdeg[i]=0;
    for(int i=1;i<=n;i++) cin>>x[i];
    if(c==11 || c==12){
        if(n==1){
            cout<<0<<'n';
            return ;
        }
        int td=x[2]-x[1];
        int can=d/td;
        if(can==0 || can==1) cout<<0<<'\n';
        else{
            cout<<max(0ll,n+1-2*can)<<'\n';
        }
        return ;
    }
    for(int i=1,j=0;i<=n;i++){
        while(j<n && x[j+1]-x[j]<=d) j++;
        solve(i,j);
        i=j; j++;
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>_;
    while(_--) work();
    return 0;
}
