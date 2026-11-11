#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],dp[100000001],maxn=-1;
int s(long long x){
    int k;
    for(int i=10000;i*i<x;i++){
        k=i;
    }
    return k;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
       // dp[i][0]=1;
    }
    sort(a+1,a+n+1);
    if(m>=100000001) printf("&d",(s(4*m+1)-1)/2+1);
    /*else{
        for(int i=0;i<n;i++){
            for(int j=0;j<=m;j++){
                if(j>a[i]-a[i-1]) maxn=max(dp[i][j-1],dp[i][j-a[i]+a[i-1]]);
            }
        }
    }*/
    else{
        for(int i=n;i>=1;i--){
            int b=0;
            for(int j=i;j>=1;j--){
                if(b+a[i]-a[j]<=m){
                    dp[i]++;
                    b+=a[i]-a[j];
                }else break;
            }
            maxn=max(maxn,dp[i]);
        }
    }
    printf("%d",maxn);
    return 0;
}
