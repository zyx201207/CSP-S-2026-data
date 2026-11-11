
#include<bits/stdc++.h>
using namespace std;
int a[200010],n,m,ans;
void dfs(int step,int x,int nxt){
    if(step==m){
        ans=max(ans,x);
        return;
    }
    for(int i=nxt+1;i<=n;i++){
        dfs(step+1,x&a[i],i);
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
        dfs(1,a[i],i);
    }
    cout<<ans;
    return 0;
}
