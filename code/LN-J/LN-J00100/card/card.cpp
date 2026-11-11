#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],vis[N],ans[N];
int main (){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=n;j>=1;j--){
            if(!vis[i] && a[j]==i){
                ans[i]=j;
                vis[i]=1;
                break;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
