#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500003],vis[500003],ans[300003];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    ans[a[n]]=n;
    for(int i=1;i<n;i++){
        int f=0;
        for(int j=1;j<=n;j++){
            if(i!=j){
                if(a[i]==a[j]){
                    ans[a[i]]=m;
                    f=1;
                    break;
                }
            }
        }
        if(f==0){
            ans[a[i]]=i-1;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
