#include<bits/stdc++.h>
using namespace std;
long long maxad=0,n,m,a[200005],k=1<<31;
void dfs(long long dep,long long ans,long long li){
    if(dep>=m){
        maxad=max(maxad,ans);
        return;
    }
    for(long long i=li+1;i<=n;i++){
        if(ans&a[i]<=maxad) continue;
        dfs(dep+1,(ans&a[i]),i);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    dfs(0,k-1,0);
    cout<<maxad;
    return 0;
}
