#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],s[N];
long long dp[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    dp[1]=1;
    for(int i=2;i<=n;i++){
        int cnt=dp[i-1]*a[i]-(s[i-1]-s[i-1-dp[i-1]]);
        if(cnt<=m){
            dp[i]=dp[i-1]+1;
        }else{
            dp[i]=dp[i-1];
        }
    }
    cout<<dp[n];
    return 0;
}
