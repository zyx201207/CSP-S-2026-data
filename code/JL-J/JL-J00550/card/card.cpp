#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],sum[500005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int l=i;l<n;l++){
            sum[l]=a[l];
            for(int p=i;p<l;p++){
                if(sum[p]==sum[l]){
                    for(int y=p;y<l;y++){
                        sum[y]=0;
                    }
                }
            }
        }
        for(int l=i;l<n;l++){
            ans[sum[l]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
