#include <bits/stdc++.h>
using namespace std;
int main ()
long long n,m,mx=-10,x;
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        x=1;
        long long y=m;
        for(int j=i-1;j>=0;j--)
        {
            if(a[i]-a[j]<=y)
            {
                y=y-a[i]+a[j];
                x++;
            }
            mx=max(mx,x);
        }
    }
    cout<<mx;
    return 0;
}
