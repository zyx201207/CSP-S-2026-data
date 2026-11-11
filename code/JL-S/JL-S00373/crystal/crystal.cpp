#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int a[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n),a[n+1]=1e18;

    int sum=0,r=0,ans=0;
    for(int l=1;l<=n;l++)
    {
        while(a[r+1]+sum+m>=a[r+1]*(r-l+2)&&r<n)
            sum+=a[++r];
        ans=max(ans,r-l+1);
        sum-=a[l];
    }
    cout<<ans<<'\n';
    return 0;
}
