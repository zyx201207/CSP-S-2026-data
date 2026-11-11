#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+5;
ll a[maxn],s[maxn];
int n;
ll m;
bool check(int l,int r)
{
    if((a[r]*((ll)r-l+1)-(s[r]-s[l-1]))<=m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    int ans0=-1;
    for(int i=1;i<=n;i++)
    {
        int r=i,l=1;
        int ans=r;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(check(mid,i))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        ans0=max(ans0,i-ans+1);
    }
    cout<<ans0;
    return 0;
}
