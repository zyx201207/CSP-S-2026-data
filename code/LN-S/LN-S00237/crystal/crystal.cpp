#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[500010],v[500010];
long long m;
long long ans;
long long dp[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    long long goal=a[(int)ceil(n/2)];
    for(int i=1;i<=n;i++) v[i]=abs(a[i]-goal);
    sort(v+1,v+n+1);
    for(int i=2;i<=n;i++)
        for(int j=m;j>=v[2];j--)
            if(j-v[i]>=0) dp[j]=max(dp[j],dp[j-v[i]]+1);
    cout<<dp[m]+1;
    return 0;
}
