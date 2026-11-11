#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200005],l,r,x[35],z,h;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    x[0]=1;
    for(int i=1;i<=30;i++)
    {
        x[i]=2*x[i-1];
    }
    for(int i=30;i>=1;i--)
    {
        z=0;
        for(int k=1;k<=31-i;k++){
            l=1000000;
            r=0;
            int y=0;
            if(k>1)
            {
                y=x[i];
            }
            for(int j=1;j<=n;j++)
            {
                if(a[j]>x[31-k]+y)
                {
                    l=j;
                    break;
                }
            }
            for(int j=n;j>=1;j--)
            {
                if(a[j]<x[32-k])
                {
                    r=j;
                    break;
                }
            }
            for(int j=l;j<=r;j++)
            {
                z++;

            }
        }
        if(z>=m)
        {
            h=x[i];
        }
        break;
    }
    cout<<h;

}
