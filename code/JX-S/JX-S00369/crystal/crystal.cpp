#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m;
long long a[500005];
long long value(int l,int r)
{
    int sum=0;
    for(int i=l;i<=r;i++)
    {
        sum+=a[l]-a[i];
    }
    return sum;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    int l=1,r=n;
    while(l<=n&&r<=n&&l<=r)
    {
        while(a[l]-a[r]>(r-l)*(a[l]-a[l+1])&&value(l,r)>m)
        {
            r--;
        }
        ans=max(ans,r-l);
        l++;
        r=n;
    }
    cout<<ans;

    return 0;
}
