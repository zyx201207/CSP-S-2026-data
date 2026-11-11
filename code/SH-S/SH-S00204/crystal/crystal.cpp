#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=n;
    while(l<=r)
    {
        long long mid=(l+r)>>1,num=0;
        for(int i=1;i<=mid;i++)
        {
            num+=(a[mid]-a[i]);
        }
        if(num>m)r=mid-1;
        else{
            l=mid+1;
            ans=max(ans,mid);
        }
    }
    cout<<ans<<endl;
    return 0;
}
