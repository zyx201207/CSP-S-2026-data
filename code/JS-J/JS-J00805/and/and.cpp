#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
bool q;
long long read()
{
    q=0;
    int c,d=0;
    long long x=0;
    c=getchar();
    while(c<'0'||c>'9')
    {
        c=getchar();
        if(c==-1)
        {
            q=1;
            return 0;
        }
        d=c;

    }
    while(c>='0'&&c<='9'||c==-1)
    {
        x=x*10+c-'0';
        c=getchar();
    }
    if(d=='-')
    {
        x*=-1;
    }
    return x;
}
bool tmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long  n,m;
    long long ans=0,z=-1234569876543;
    n=read();
    m=read();
    vector<long long > a(n),k;
    for(long long i=0;i<n;i++)
    {
        a[i]=read();
        if(a[i]>z)
        {
            z=a[i];
        }
    }
    k=vector<long long >(ceil(log2(z))+1);
    for(long long i=0;i<n;i++)
    {
        for(long long j=0;(1<<j)<=a[i];j++)
        {
            if(a[i]/(1<<j)%2==1)
            {
                k[j]++;
            }
        }
    }
    for(long long i=0;i<k.size();i++)
    {
        if(k[i]<m)
        {
            for(long long j=0;j<n;j++)
            {
                if(a[j]/(1<<i)%2==1)
                {
                    a[j]-=(1<<i);
                }
            }
        }
    }
    sort(a.begin(),a.end(),tmp);
    ans=a[0];
    for(long long i=1;i<m;i++)
    {
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
