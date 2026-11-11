#include<bits/stdc++.h>
using namespace std;
int a[200067];
int bl[67];
bool vis[67];
int n,m,ans;
void dfs(int dep){
    if(dep==m){
        int aa=bl[0];
   //     for(int i=0;i<m;i++){
    //        cout<<bl[i]<<' ';
      //  }
        cout<<endl;
        for(int i=1;i<m;i++){
            aa=aa&bl[i];
        }
        ans=max(aa,ans);
        return;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bl[dep]=a[i];
            vis[i]=1;
            dfs(dep+1);
            vis[i]=0;
        }

    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0);
    cout<<ans;
    return 0;
}
