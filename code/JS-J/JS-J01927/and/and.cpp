#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],ans=-1e9,chosen[200005];
bool vis[200005];
ll get(){
    ll ans = chosen[1];
    for (int i=2;i<=m;i++){
        ans &= chosen[i];
    }
    return ans;
}
void get_chosen(int step){
    cout << step << ' ';
    for (int i=1;i<=m;i++){
        cout << chosen[i] << ' ';
    }
    cout << endl;
}
void dfs(int step){
    if (step==m+1){
        // get_chosen(step);
        ans = max(ans,get());
        return;
    }
    for (int i=1;i<=n;i++){
        if (vis[i]) continue;
        chosen[step] = a[i];
        vis[i] = 1;
        dfs(step+1);
        vis[i] = 0;
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}