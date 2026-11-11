#include<bits/stdc++.h>
using namespace std;
int n,m,c[10001],a[10001];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int b;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(a[i]>=a[j])
            {
                int z=a[i];
                a[i]=a[j];
                a[j]=z;
            }
        }
    }//paixu

    for(int p=1;p<=n;p++)
    {
        b=p;
        if(a[b]<=0)
        {
            for(int i=b;i<=n;i++)
            {
                if(a[i]>0)
                {
                    b=i;
                }
            }
            for(int j=m;j>=1;j++)
            {
                int i=b-1;
                if(a[i]<a[b])
                {
                    a[i]++;
                }
                if(a[i]==a[b])
                {
                    i--;
                }
            }
            for(int i=1;i<=b;i++)
            {
                if(a[i]==a[b])
                {
                c[p]++;
                }
            }
            c[p]+=2;
            p=b;
        }
        else{
            for(int j=m;j>=1;j--)
            {
                int i=b-1;
                if(a[i]<a[b])
                {
                    a[i]++;
                }
                if(a[i]==a[b])
                {
                    i--;
                }
            }
            int suma=0;
            for(int i=1;i<=b;i++)
            {
                if(a[i]==a[b])
                {
                    c[p]++;
                }
            }
            c[p]++;
        }
    }
    int minia=0;
    for(int i=1;i<=n;i++)
    {
        if(c[i]>=minia)
        {
            minia=c[i];
        }
    }
    cout<<minia;
    return 0;
}
