#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005],teA,teB,cha;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	cha=a[2]-a[1];
	for(long long i=3;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)
        {
            teA=1;
        }
        if(a[i]-a[i-1]!=cha)
        {
            teB=1;
        }
    }
    if(n==1)
    {
        cout<<1;
    }
    if(teA==0||teB==0)
    {
        long long f=0;
        long long ch=a[2]-a[1];
        c[0]=0;
        for(long long i=1;i<=n-1;i++)
        {
            c[i]=c[i-1]+ch*i;
            if(c[i]>m)
            {
                cout<<i;
                f=1;
                break;
            }
        }
        if(f==0)
        {
            cout<<n;
        }
    }
    else
    {
        sort(a+1,a+n+1);
        for(long long i=1;i<=n-1;i++)
        {
            b[i]=a[i+1]-a[i];
        }
        c[0]=0;
        long long f=0;
        for(long long i=1;i<=n-1;i++)
        {
            c[i]=c[i-1]+b[i]*i;
            if(c[i]>m)
            {
                cout<<i;
                f=1;
                break;
            }
        }
        if(f==0)
        {
            cout<<n;
        }
    }
	return 0;
}
