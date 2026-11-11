#include<iostream>
using namespace std;
using ll=long long;
ll n,m;
ll ans;
ll a[2000005];
void dfs(ll id,ll cnt,ll sum){
    if(sum<ans)return;
    if(cnt>=m){
        ans=max(ans,sum);
        return;
    }
    if(n-id+1<m-cnt)return;
    for(ll i=id;i<=n;i++){
        dfs(i+1,cnt+1,sum&a[i]);
        dfs(i+1,cnt,sum);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0x7fffffff);
    cout<<ans;
    return 0;
}
