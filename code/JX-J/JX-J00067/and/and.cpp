#include<bits/stdc++.h>
using namespace std;
int a[200005],ans=-1e9,numm[200005],vis[200005],n,m;
void dfs(int s,int e){
    if(s==m+1){
        int cnt=numm[1];
        for(int i=2;i<=m;i++){
            cnt=cnt&numm[i];
        }
        ans=max(ans,cnt);
    }
    for(int j=e;j<=n;j++){
        if(!vis[j]){
            vis[j]=1;
            numm[s]=a[j];
            dfs(s+1,j);
            vis[j]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,1);
    cout<<ans;
    return 0;
}
