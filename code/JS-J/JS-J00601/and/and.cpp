#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=INT_MIN;
int a[200010];
void dfs(int i,int cnt,int res){
    if(cnt==m){
        ans=max(ans,res);
        return;
    }
    for(int j=i+1;j<=n;j++){
        dfs(j,cnt+1,res&a[j]);
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        dfs(i,1,a[i]);
    }
    cout<<ans;
    return 0;
}
