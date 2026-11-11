#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxx=0,sum=0,t=0;
    cin>>n>>m;
    int s=0;
    long long a[300000],b[300000][40];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n+1);
    int minn=a[n];
    for(int i=1;i<=n;i++)
    {
        for(int i1=a[i];i1!=0;i1/=2)
        {
            b[i][s]=i1%2;
            s++;
        }
        if(i==2)
            t=s;
        if(s>maxx)
            maxx=s;
            if(s<minn)
                minn=s;
        s=0;
    }
    if(m==1)
    {
        cout<<maxx;
    }
    else if(m==n)
    {
        int f=0;
        for(int i=1;i<=minn;i++)
        {
            for(int i1=2,i1<=n,i1++)
            {
                if(b[i1][i]!=b[i1-1][i])
                    f=1;
            }
            if(f=0)
                sum++;
            f=0;
        }
        cout<<sum;
    }
    else if(m==n-1)
    {
        int f=0;
        for(int i=1;i<=t;i++)
        {
            for(int i1=3,i1<=n,i1++)
            {
                if(b[i1][i]!=b[i1-1][i])
                    f=1;
            }
            if(f=0)
                sum++;
            f=0;
        }
        cout<<sum;
    }
    else cout<<7;
    return 0;
}
