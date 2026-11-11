#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        long long num[300005]={0},r;
        for(int j=i;j<=n;j++){
            num[++r]=a[j];
            for(int k=r;k>=1;k--){
                if(num[k]==a[j]){
                    for(int l=k;l<r;l++){
                        num[l]=0;
                    }
                    r-=k;
                    break;
                }
            }
        }
        for(int j=1;j<=r;j++){
            ans[num[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
