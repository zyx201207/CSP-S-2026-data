#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long dp[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i+=1){
        scanf("%lld",&a[i]);
    }
    dp[0]=9223372036854775807;
    for(long long i=1;i<=n;i+=1){
        for(long long j=m;j>0;j-=1){
            dp[j]=max((dp[j-1] & a[i]),dp[j]);
//            cout<<dp[j]<<" ";
        }
//        cout<<" "<<dp[m]<<"\n";
    }
/*
    for(int i=0;i<=m;i+=1){
        cout<<dp[i]<<' ';
    }*/
    cout<<dp[m];
    return 0;
}