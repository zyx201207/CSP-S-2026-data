#include<bits/stdc++.h>
using namespace std;
long long a[500005],z[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n,m,ans=1,lt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) z[i]=z[i-1]+(i-1)*(a[i]-a[i-1]);
    for(int i=2;i<=n;i++)
    {
        if(z[i]-z[lt]-lt*(a[i]-a[lt])<=m)
        {
            ans=max(ans,i-lt);
            continue;
        }
        long long l=lt,r=i+1;
        lt=i-1;
        while(l<r)
        {
            long long mid=l+(r-l)/2,ansi;
            ansi=z[i]-z[mid]-mid*(a[i]-a[mid]);
            if(ansi<=m)
            {
                lt=min(lt,mid);
                r=mid;
            }
            else l=mid+1;
        }
        ans=max(ans,i-lt);
    }
    cout<<ans<<'\n';
    return 0;
}
