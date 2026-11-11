#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],ans=-1;

void dfs(ll idx,ll cnt,ll sum){
    if(cnt==m){
        ans=max(ans,sum);
        return;
    }
    //
    for(ll i=idx+1;i<=n;i++){
        dfs(i,cnt+1,sum&a[i]);
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //
    cin >> n >> m;
    //
    bool is=1,is2=1;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    //
    for(ll i=1;i<=n;i++){
        if(a[i]!=pow(2,i)-1) is2=0;
    }
    //
    if(is2){
        cout << a[n-m+1];
        return 0;
    }
    //
    for(ll i=1;i<=n;i++){
        dfs(i,1,a[i]);
    }
    //
    cout << ans;
    //
    return 0;
}
