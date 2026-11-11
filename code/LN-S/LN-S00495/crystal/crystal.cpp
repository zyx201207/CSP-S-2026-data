#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500001];
long long zhuan;
long long k=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    zhuan=a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=zhuan)
        {
            k++;
        }
    }
    if(k==0)
    {
        cout<<n;
        return 0;
    }
    long long l;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                l=a[j+1];
                a[j+1]=a[j];
                a[j]=l;
            }
        }
    }
    long long ans;
    long long he;
    for(int i=n;i>=1;i--)
    {
        he=0;
        for(int j=i-1;j>=1;j--)
        {
           he=he+a[i]-a[j];
        }
        if(he<=m)
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}
