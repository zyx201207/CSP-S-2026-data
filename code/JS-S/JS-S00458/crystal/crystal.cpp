#include<bits/stdc++.h>
using namespace std;
const int MX=5e5+10;
long long a[MX];
unsigned long long b[MX];
int main()
{
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,i;
    unsigned long long m;
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    b[1]=0;
    for(i=2;i<=n;i++)
    {
        b[i]=(a[i]-a[i-1])*(i-1);
        b[i]+=b[i-1];
    }
    int l=1,r=n,mid,ans=1;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(b[mid]>m) r=mid-1;
        else
        {
            l=mid+1;
            ans=mid;
        }
    }
    cout<<ans;
    return 0;
}
