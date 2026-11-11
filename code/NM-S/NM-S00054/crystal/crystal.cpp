#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005]={};
long long b[10]={};
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long r;
    for(int i=1;i<=n;i++)
    {
       for(int j=1;j<=n;j++)
       {
           if(a[j]<a[j+1])
           {
               if(m>=a[j+1]-a[j]-1)
               {
                   m=m-a[j+1]+a[j];
                   a[j]=a[j+1];
               }
               else
               {
                   break;
               }
           }
       }
    }
    long long s=0;
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=10;j++)
        {
            if(a[i]==j)
            {
                b[j]++;
            }
        }
    }
    for(int i=1;i<=10;i++)
    {
        if(b[i]>s)
        {
            s=b[i];
        }
    }
    cout<<s<<endl;
    return 0;
}
