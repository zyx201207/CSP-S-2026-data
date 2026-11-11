#include<bits/stdc++.h>
using namespace std;
long long ans=0;
long long n,m;
long long  a[200005];
long long  dp[200005];
bool cmp(long long  x,long long  y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long  i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    dp[1]=a[1];
    for(long long  i=2;i<=n;i++){
        for(long long  j=m;j>1;j--){
            dp[j]=max(dp[j],dp[j-1]&a[i]);
        }
    }
    cout<<dp[m];
    return 0;
}
