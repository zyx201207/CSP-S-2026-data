#include <bits/stdc++.h>
using namespace std;

int n;
int a[500005];
long long cost,l,r,sum,maxx,ans;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>cost;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(l=1,r=1,sum=0,maxx=a[1],ans=1;r<=n && l<=n && l<=r;r++)
    {
        sum+=(a[r]-maxx)*(r-l);
        if(sum>cost)
        {
            while(sum>cost)
            {
                sum-=(a[r]-a[l]);
                l++;
            }
        }
        maxx=a[r];
        if(l<=r && sum<=cost)
        {
            ans=max(ans,r-l+1);
        }
        //cout<<l<<" "<<r<<" "<<sum<<" "<<maxx<<" "<<ans<<endl;
    }
    cout<<ans;
    return 0;
}