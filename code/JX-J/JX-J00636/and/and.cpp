#include<bits/stdc++.h>
using namespace std;
long long a[100000]={0},b[100000]={0},c[100000]={0},d[100000]={0},z[100000]={0};
long long n,m,t=0,h=0,l=1,sum=0,r=1;;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {

            t=0;
            h=0;
            l=1;
            sum=0;
            a[100000]={0};
            b[100000]={0};
            c[100000]={0};
            d[100000]={0};
            z[100000]={0};
            int p=i,q=j;
            while(p)
            {
                t++;
                a[t]=p%2;
                p=p/2;
            }
            while(q)
            {
                h++;
                b[h]=q%2;
                q=q/2;
            }
            for(int k=max(t,h);k>=1;k--)
            {
                if(a[k]==b[k])
                {
                    d[k]=a[k];
                }
                else
                {
                    d[k]=0;
                }
            }
            for(int k=max(t,h);k>=1;k--)
            {
                sum=sum+pow(2,l);
                l++;
            }
            z[r]==sum;
            r++;
        }
    }
    for(int i=1;i<=r-1;i++)
    {
        for(int j=i+1;j<=r;j++)
        {
            if(z[i]<z[j])
            {
                swap(z[i],z[j]);
            }
        }
    }
    cout<<z[1];
    return 0;
}
