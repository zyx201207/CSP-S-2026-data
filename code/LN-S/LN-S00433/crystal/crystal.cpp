#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
long long d[5000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    long long ans=1;
    cin>>n>>m;
    m%=998244353;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n-1;i++){
        d[i]=a[i+1]-a[i];
    }
    long long sum=0;
    for(long long i=1;i<=n;i++){
        sum=(sum+d[i]*i)%998244353;
        if(sum>m) break;
        ans++;
    }
    cout<<ans;
    return 0;
}
