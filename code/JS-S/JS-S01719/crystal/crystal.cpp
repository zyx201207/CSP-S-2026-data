#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],l,mid,r,ans,s,out;
int main()
{
    std::cin.tie(0);std::cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }sort(a+1,a+n+1);
    l=a[1];r=a[n];
    while(l<=r)
    {
        mid=(l+r)/2;
        s=0;ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]<=mid)
            {
                ans++;
                s+=(mid-a[i]);
            }
        }
        if(s>=m)r=mid-1;
        else l=mid+1;
    }cout<<ans;
    return 0;
}
