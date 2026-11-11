#include<bits/stdc++.h>
using namespace std;
long long n,i,j,a[500010],c[500010],m,l,ans=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(i=2;i<=n;i++)
    {
        c[i]=a[i]-a[i-1];
    }
    for(i=1;i<=n;i++)
    {
        l=c[i-1]+(i-1)*c[i];
        c[i]=l;
        if(l<=m)
        {
            ans=i;
        }
        else
        {
           break;
        }
    }
    cout<<ans;
    return 0;
}
