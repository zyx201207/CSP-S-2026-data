//migrate

#include<bits/stdc++.h>
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);--i)
#define int long long
using namespace std;
const int N=310,inf=1e18;
int a[N],mi[N],cnt[N];
int res=0;
int n,m;
void dfs(int u,int dep){
    if(dep>mi[u])return ;
    if(dep<mi[u]){
        mi[u]=dep;
        cnt[u]=1;
    }
    else if(mi[u]==dep)++cnt[u];
    L(i,u+1,n){
        if(abs(a[i]-a[u])>m)break;
        dfs(i,dep+1);
    }

}
void solve(){
    cin>>n>>m;
    L(i,1,n)cin>>a[i];
    int ans=0;
    L(i,1,n){
        L(j,i,n){
            mi[j]=inf;
        }
        dfs(i,0);
        L(j,i+1,n){
            if(cnt[j]==2)++ans;
            //if(i==1)cout<<cnt[j]<<" ";
        }
    }
    //cout<<"\n";
    cout<<ans<<"\n";
}
signed main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        solve();

    }
    return 0;
}
