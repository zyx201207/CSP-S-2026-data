#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,q[500005],a[500005],l=1,r=1,ans=1,x;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)q[i]=q[i-1]+a[i];
    while(1)
    {
        if(l==n||r==n+1)break;
        x=q[r-1]-q[l-1];
        x=(r-l)*a[r]-x;
        if(x<=m)
        {
            ans=max(ans,r-l+1);
            r++;
        }
        else l++;
    }
    cout<<ans;
    return 0;
}
