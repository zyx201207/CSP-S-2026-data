#include<iostream>
using namespace std;
int n,m,a[500010],ans[200010],f[500010],vis[200010];
long long x;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vis[i]=0;
        }
        x=i-1;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==0){
                f[x]=a[j];
                vis[a[j]]=x;
                x++;
            }else{
                for(int k=vis[a[j]]+1;k<=x;k++){
                    vis[f[k]]=0;
                }
                x=vis[a[j]]+1;
            }
        }
        for(int j=i;j<=x;j--){
            ans[f[j]]++;
        }

    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
