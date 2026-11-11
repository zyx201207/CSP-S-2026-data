#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005];
int ans[3005],t[3005];
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //4 3
    //1 2 1 3
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(t[a[j]]==0) {
                t[a[j]]++;
            } else if(t[a[j]]>=1){
                for(int k=j-1;k>=i;k--){
                    if(a[k]==a[j]){
                        for(int l=k;l<=j;l++){
                            t[a[l]]=0;
                        }
                        break;
                    }
                }
                t[a[j]]++;
            }
        }
        for(int j=i;j<=n;j++){
            if(t[a[j]]>=1) ans[a[j]]++;
            t[a[j]]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
