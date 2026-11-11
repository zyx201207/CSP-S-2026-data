#include<bits/stdc++.h>
using namespace std;
int a[500005],aa[500005][500005];
int n,m,ans=0;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            aa[i][j]=a[i]-a[j];
        }
    }
    for(int i=1;i<=n;i++){
        int sun=0;
        for(int j=0;j<=i;j++){
            sun+=aa[i][i-j];
            if(sun>m){
                ans=max(ans,j);
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
