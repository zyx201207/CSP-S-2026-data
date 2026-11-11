#include <bits/stdc++.h>
using namespace std;
int n,m,p,vis[200005];
long long a[200005],an[200005],ans;
int dfs(int x){
    if(x==m){
        ans=max(an[x],ans);
        cout<<ans<<endl;
        return ans;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])    continue;
        an[x+1]=an[x]&a[i];
        vis[i]=1;
        dfs(x+1);
        an[x+1]=111111111111;
        vis[i]=0;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        an[i]=111111111111;
    }
    dfs(1);
    cout<<ans;
}
