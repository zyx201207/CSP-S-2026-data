#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    long long ans=a[n];
    for(long long i=n;i>=n-m+1;i--)ans=ans&a[i];
    cout<<ans;
    return 0;
}
//wo yao li kai zhe ge mei li de shi jie le
