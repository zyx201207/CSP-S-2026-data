#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long s[500005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++)
    {
        s[i]=a[i]-a[i-1];
    }
    long long ans=1,ss=0,f=0;
    for(int i=2;i<=n;i++)
    {
        if(f==1)
        {
            f=0;
            ss=ss-a[i-1]+a[i-1-ans];
        }
        if(ss+s[i]*ans<=m)
        {
            ss=ss+s[i]*ans;
            ans++;
        }
        else
        {
            ss=ss+s[i]*ans;
            f=1;
        } 
    }
    cout<<ans;
    return 0;
}