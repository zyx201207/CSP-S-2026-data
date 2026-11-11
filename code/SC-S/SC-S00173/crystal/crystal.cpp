#include<bits/stdc++.h>
using namespace std;
long long n,m,s;
long long Y=0;
long long a[10000100];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int j=1;j<n+1;j++)
    {
        if(a[j+1]-a[j]>=0 && a[j+1]-a[j]<=m)
        {
            s=a[j+1]-a[j];
            a[j]=a[j]+s;
            m=m-s;
            Y++;
        }
    }

    cout<<Y;
    return 0;
}
