#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005],b[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++) b[j]=a[j];
        for(int j=i;j<=n;j++){
            for(int k=j-1;k>=i;k--){
                if(b[k]==b[j]){
                    for(int l=k;l<=j-1;l++) b[l]=0;
                    break;
                }
            }
        }
        for(int j=i;j<=n;j++) ans[b[j]]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
