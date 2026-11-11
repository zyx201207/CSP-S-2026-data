#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[500050];
long long b[500050];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
    ans=1;
    for(long long i=2;i<=n;i++)
    {
        if(i*a[i]-b[i]>m) continue;
        ans=i;
    }
    cout<<ans;
    return 0;
}
