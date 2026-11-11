#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],ans;
void dfs(ll x,ll c,ll h){
    if(c==m||x>n){if(c==m)ans=max(ans,h);return;}
    dfs(x+1,c+1,h&a[x]);
    dfs(x+1,c,h);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,0,0xffffffff);
    cout<<ans;
    return 0;
}
