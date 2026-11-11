#include<bits/stdc++.h>
using namespace std;
bool v[200009];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,a[200009],ma=0,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    if(m==n)
    {
        ma=a[1];
        for(long long i=2;i<=n;i++)
        {
            ma=ma&a[i];
        }
        cout<<ma;
        return 0;
    }
    else if(m==1)
    {
        sort(a+1,a+n+1);
        cout<<a[n];
    }
    else if(m==2)
    {
        for(long long i=1;i<=n;i++)
        {
            for(long long j=i+1;j<=n;j++)
            {
                ma=max(ma,a[i]*a[j]);
            }
        }
        cout<<ma;
        return 0;
    }
    return 0;
}
