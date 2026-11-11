#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005];
long long n,m;
bool check(int k)
{
    for(int i=k;i<=n;i++)
        if(k*a[i]-(s[i]-s[i-k])<=m)
            return true;
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid))
            l=mid;
        else
            r=mid-1;
    }
    cout<<l<<endl;
    return 0;
}