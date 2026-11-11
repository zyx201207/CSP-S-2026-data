#include<bits/stdc++.h>
using namespace std;
long long dp[1000000],n,m,maxn=-2147484238,num[1000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    sort(num+1,num+n+1);
    dp[0]=num[0];
    for(int i=1;i<m;i++){
        dp[i]=max(dp[i-1],dp[i-1]&num[i]);
        if(dp[i]>maxn)maxn=dp[i];
    }
    cout<<maxn;
    return 0;
}
