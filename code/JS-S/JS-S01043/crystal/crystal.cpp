#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans=1;
long long a[500005],sum[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        if((sum[i]+m)/i>=a[i])
            ans=i;
    }
    cout<<ans;
    return 0;
}
