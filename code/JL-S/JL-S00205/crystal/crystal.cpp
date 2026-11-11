#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long a[5000005];
    long long n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    long long sum=0,x,ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            sum+=(a[i]-a[j]);
            if(sum>m)
            {
                x=i-1;
                break;
            }
            if(sum==m)
            {
                x=i;
                break;
            }
        }
    }
    for(int i=0;i<=x;i++)
    {
        ans++;
    }
    cout<<ans;
}
