#include<bits/stdc++.h>
using namespace std;
long long a[500009],s[500009];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int mx=-1;
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i;
        for(;l<r;)
        {
            int mid=(l+r)/2;
            if((s[i]-s[mid-1])>=a[i]*(i-mid+1)-m) r=mid;
            else l=mid+1;
        }
        mx=max(mx,i-l+1);
    }
    cout<<mx;
    return 0;
}
