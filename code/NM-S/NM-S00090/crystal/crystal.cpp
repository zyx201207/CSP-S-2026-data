#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[9999999],b[9999999];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=500005)
    {

        long long sum=0,ans=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<i; j++)
            {
                sum+=a[i]-a[j];
            }
            if(sum<=m)
            {
                ans=i;
                sum=0;
            }
        }
        cout<<ans;
    }
    else
    {

        long long unplus=a[2]-a[1];
        long long temp=1;
        for(int i=n; i>=1; i--)
        {
            b[i-1]=b[i]+temp*unplus;
            temp++;
        }
        sort(b+1,b+n+1);
        int ans;
        for(int i=1; i<=n; i++)
        {
            if(b[i]<=m)
            {
                ans=i;
            }
            else break;
        }
        cout<<ans;
    }
    return 0;
}
