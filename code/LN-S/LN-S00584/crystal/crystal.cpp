#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=5e5+10;
int a[N];
int ans=0;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    int l=1,r=1,sum=0;
    while(l<=n&&r<=n)
    {
        ans=max(ans,r-l+1);
        if(r==n)
        {
            break;
        }
        if(sum+a[l]-a[r+1]<=m)
        {
            sum+=a[l]-a[r+1];
            r++;
        }
        else
        {
            sum-=(a[l]-a[l+1])*(r-l);
            l++;
        }
    }
    cout<<ans;
    return 0;
}
