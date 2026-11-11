#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[2][200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<a[1];
        return 0;
    }
    int arr=0;
    for(int i=0;i<=m;i++){
        dp[0][i]=-1;
    }
    while(arr<=n-1){
        for(int i=0;i<=m-1;i++){
            if(arr>n-m&&n-arr>=m-i-1){
                dp[(arr+1)%2][i+1]=dp[arr%2][i]&a[arr+1];
            }else{
                dp[(arr+1)%2][i+1]=max(dp[arr%2][i]&a[arr+1],dp[arr%2][i+1]);
            }
            //cout<<dp[(arr+1)%2][i+1]<<" ";
        }
        arr++;
        //cout<<endl;
    }
    cout<<dp[n%2][m];
    return 0;
}
