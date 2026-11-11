#include<bits/stdc++.h>
using namespace std;
int a[200005],m,n,dp[200005],max1;
string s;
long long f;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }dp[1]=a[1];
        for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
                if(j>=i){dp[j]=max(dp[j-1]&a[i],dp[j]);}

        }dp[i+1]=dp[i];
    }cout<<dp[n];
    return 0;
}
