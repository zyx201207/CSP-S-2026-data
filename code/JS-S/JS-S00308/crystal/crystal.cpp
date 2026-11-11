#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,a[500005],t=0,s=0,mi,ma;
    cin>>n>>m;
    cin>>a[1];
    mi=a[1];
    ma=a[1];
    for(long long i=2;i<=n;i++)
    {
        cin>>a[i];
        mi=min(mi,a[i]);
        ma=max(ma,a[i]);
    }
    int x=a[2]-a[1];
    for(long long i=3;i<=n;i++)
    {
        if(a[i]-a[i-1]!=x)
        {
            t=1;
        }
    }
    if(t==0)
    {
        while(m<t*x)
        {
            t++;
            if(t>n)
            {
                t=n;
            }
            if(m>=t*x)
            {
                m-=t*x;
            }
            else if(m==0)
            {
                s=t;
                break;
            }
            else
            {
                s=t-1;
                break;
            }
        }
        cout<<s<<endl;
        return 0;
    }
    else
    {
        long long z;
        for(long long i=mi;i<=ma;i++)
        {
            long long x=0,y=0;
            for(long long j=1;j<=n;j++)
            {
                if(i>a[j])
                {
                    x+=i-a[j];
                    y++;
                }
                if(i==a[j])
                {
                    y++;
                }
            }
            if(m>x)
            {
                z=y;
            }
            else if(m==x)
            {
                cout<<y<<endl;
                return 0;
            }
            else if(m<x)
            {
                if(z!=n)
                {
                    cout<<z<<endl;
                    return 0;
                }
                if(z==n)
                {
                    cout<<z-1<<endl;
                    return 0;
                }
            }
        }
    }
}
