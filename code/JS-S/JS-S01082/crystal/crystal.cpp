#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50050],ans=0;
long long num(long long x){
    long long dp[50050],sum=0;
    dp[x]=0;
    for(long long i=x+1;i<=n;i++){
        dp[i]=dp[i-1]+a[i]-a[i-1];
        if(dp[i]!=dp[i-1]){
            sum+=dp[i];
        }
        if(sum>m) return i-x;
    }
    return n-x;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        ans=max(ans,num(i));
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);

    return 0;
}
