#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(long long x,long long y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    cin>>a[1];
    long long sum=a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        sum=(sum&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    if(m==1)
    {
        cout<<a[1];
        return 0;
    }
    if(m==2)
    {
        cout<<(a[1]&a[2]);
        return 0;
    }
    if(m==n)
    {
        cout<<sum;
        return 0;
    }
    long long ans=a[1];
    for(int i=2;i<=m;i++)
    {
        ans=(ans&a[i]);
    }
    cout<<ans;
    return 0;
}
