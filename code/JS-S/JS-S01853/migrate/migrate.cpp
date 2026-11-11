#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
typedef pair<ll,ll> PII;
ll c,t,n,d,x[N],cnt[N],mdep[N];
void dfs(ll u,ll dep){
    if(dep>mdep[u])return;
    else if(dep==mdep[u]){
        cnt[u]++;
    }else{
        cnt[u]=1;
        mdep[u]=dep;
    }
    if(cnt[u]==3)return;
    for(int v=u+1;x[v]-x[u]<=d&&v<=n;v++){
        dfs(v,dep+1);
    }
}
void solve(){
    
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(cnt,0,sizeof cnt);
        memset(mdep,0x3f,sizeof mdep);
        dfs(i,0);
        for(int j=i+1;j<=n;j++){
            if(cnt[j]==2){
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}
void solveA(){
    ll diff=x[2]-x[1];
    ll maxx=x[n]-x[1];
    if(d<diff||d>=maxx||(d>=diff&&d<diff*2))cout<<0<<'\n';
    else cout<<n-2*(d/diff)+1<<'\n';
}
bool check(){
    ll diff=x[2]-x[1];
    for(int i=2;i<=n;i++){
        if(x[i]-x[i-1]!=diff)return 0;
    }
    return 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(check())solveA();
        else solve();
    }
	return 0;
}
