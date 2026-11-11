#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001],i;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=1;i<n;i++)
    {
        m-=(a[i]-a[i-1])*i;
        if(m<=0) break;
    }
    while(a[i]==a[i+1])
    {
        i++;
        break;
    }
    cout<<i+1;
    return 0;
}
