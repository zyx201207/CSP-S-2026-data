#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],cs[300005],vis[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            if (vis[a[i]]==0){
                vis[a[i]]=1;
            }
            else{
                int q=j-1;
                while (a[q]!=a[j]||vis[a[q]]==0){
                    q--;
                    vis[a[q]]=0;
                }
                vis[a[--q]]=0;
            }
        }
        for (int j=i;j<=n;j++){
            if (vis[a[j]]==1){
                cs[a[j]]++;
            }
        }
    }
    for (int i=1;i<=m;i++){
        cout<<cs[i]<<" ";
    }
    return 0;
}
