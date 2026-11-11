#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],f[200005],ans=0;
int v=1073741823;
bool ok[200005];
void dfs(int cnt,int sum){
    if(cnt==m){
        ans=max(ans,sum);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(ok[i]){
            ok[i]=false;
            dfs(cnt+1,sum&a[i]);
            ok[i]=true;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ok[i]=true;
    }

    dfs(0,v);
    cout<<ans;
    return 0;
}
