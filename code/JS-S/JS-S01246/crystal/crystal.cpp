#include<bits/stdc++.h>
using namespace std;
long long n,m,t=0;
long long e[500005],d[500005],k;
bool a=true,b=true;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>e[i];
        if(e[i]!=i)
        {
            a=false;
        }
        if(i==2)
        {
            k=e[2]-e[1];
        }
        else if(i>2)
        {
            if(e[i]-e[i-1]!=k)
            {
                b=false;
            }
        }
    }
    if(a==true)
    {
        for(int i=n-1;i>=1;i--)
        {
            long long m1=(n-i+1)*(n-i)/2;
            if(m1>m)
            {
                break;
            }
            t=max(t,n-i+1);
        }
        cout<<t<<endl;
        return 0;
    }
    if(b==true)
    {
        for(long long i=2;i<n;i++)
        {
            long long m1=k*((i+1)*i/2);
            if(m1>m)
            {
                break;
            }
            t=max(t,i+1);
        }
        cout<<t<<endl;
        return 0;
    }
    sort(e+1,e+n+1);
    for(int i=1;i<n;i++)
    {
        d[i]=e[i+1]-e[i];
    }
    for(int i=1;i<n;i++)
    {
        long long m1=m,t1=1,j=i;
        while(m1>0&&j<=n)
        {
            m1=m1-d[j]-d[j]*(t1-1);
            if(m1<0)
            {
                break;
            }
            j++;
            t1++;
            //cout<<m1<<j<<t1<<endl;
        }
        t=max(t,t1);
    }
    cout<<t<<endl;
    return 0;
}
