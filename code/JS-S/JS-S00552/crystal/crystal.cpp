#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool f[500001];
long long m,a[500001],sum[500001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int l=1,r=1;
    while(r<=n)
    {
        r++;
        while(sum[r]-sum[l-1]+m<(r-l+1)*a[r]) l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
