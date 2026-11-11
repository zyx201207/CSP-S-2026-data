#include<bits/stdc++.h>
using namespace std;
struct intdp {
    long long data;
    int sum=0;
}dp[200005];
int n=0,m=0,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[1].data=a[1];
    dp[1].sum=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(dp[j].data&a[i]>a[i]&&dp[j].sum<=m){
                dp[i].data=dp[j].data&a[i];
                dp[i].sum=dp[j].sum+1;
            }
            else{
                dp[i].data=a[i];
                dp[i].sum=1;
            }
        }
    }
    cout<<dp[n].data;
    return 0;
}
