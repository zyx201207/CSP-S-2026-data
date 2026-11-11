#include<bits/stdc++.h>
using namespace std;
const int N=250000;
int n,m,a[N],vis[N];
int ans=-99;
void dfs(int k,int sum){
    if(sum<=ans) return ;
    if(k==m){
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            int su;
            if(k==0) su=a[i];
            else su=a[i]&sum;
            dfs(k+1,su);
            vis[i]=0;
        }
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

    }
    dfs(0,0);
    cout<<ans;
    return 0;
}
