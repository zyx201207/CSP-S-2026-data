#include <bits/stdc++.h>
using namespace std;
#define i128 __int128
#define int long long
const int N=500010;
int n,m,ans=0;
int a[N];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int tot=0;
    for (int l=1,r=1;r<=n;r++)
    {
        tot+=a[r];
        while ((i128)a[r]*(r-l+1)-tot>(i128)m&&l<=r)
        {
            tot-=a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<endl;
    return 0;
}