#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans=-2e9;
void dfs(int now,int x,int y){
    if(x==m){
        ans=max(ans,y);
        return;
    }
    if(now>n) return;
    if(x==0){
        dfs(now+1,x+1,a[now]);
        dfs(now+1,x,0);
    }
    else{
        dfs(now+1,x+1,(y&a[now]));
        dfs(now+1,x,y);
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
