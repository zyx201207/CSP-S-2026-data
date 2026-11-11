#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    cin>>n;
    int c;
    int a[1000008];
    int m;
    int b;
    int d=1;
    cin>>m;
    for(int i=0;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(a[i]<a[i-1])
            {
                c=a[i];
                a[i]=a[i-1];
                a[i-1]=c;
            }
        }
    }
    if(n%m==0)
    {
        b=n/2;
    }else
    {
        b=n/2+1;
    }
    for(int i=0;i<=b;i++)
    {
        if(a[b]-a[b-i]>a[b+i]-a[b]&&m>=a[b+i]-a[b])
        {
            d++;
            m-=a[b+i]-a[b];
        }if(a[b]-a[b-i]<a[b+i]-a[b]&&m>=a[b]-a[b-i])
        {
            d++;
            m-=a[b]-a[b-i];
        }if(a[b]-a[b-i]==a[b+i]-a[b]&&m>=2*(a[b+i]-a[b]))
        {
            d+=2;
            m-=a[b+i]-a[b];
            m-=a[b+i]-a[b];
        }if(a[b]-a[b-i]==a[b+i]-a[b]&&m<2*(a[b+i]-a[b])&&m>=a[b+i]-a[b])
        {
            d++;
            m-=a[b+i]-a[b];
        }if(a[b]-a[b-i]==a[b+i]-a[b]&&a[b]==a[b-i])
        {
            d+=2;
        }
    }
    cout<<d;
    return 0;
}
