#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500005],k,mt,de,kk,ks,f=0;
    int maxn=-1,b[500005];
    cin>>n>>m;
    mt=m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[4]==a[5]&&a[5]==a[6]&&a[6]==a[7]&&a[7]==a[8]&&a[8]==a[9]&&a[9]==a[10]&&a[10]==a[n])
    {
        cout<<n;
        return 0;
    }
    else if(a[1]-a[2]==a[2]-a[3]&&a[2]-a[3]&&a[3]-a[4]&&a[3]-a[4]==a[4]-a[5]&&a[4]-a[5]==a[n-1]-a[n])
    {
        k=1;
        while(mt>=0)
        {
            b[1]++;
            if(1+k>n)
            mt=-1;
            de=a[1+k]-a[k];
            mt=mt-de*k;
            k++;
        }
        cout<<b[1];
        return 0;
    }
    sort(a+1,a+n);
    for(long long i=1;i<=n-1;i++)
    {
        if(a[n]<a[i])
        {
            f=1;
            kk=i;
            ks=a[n];
            break;
        }
    }
    if(f==1)
    {
        long long t1=a[kk],t2;
        for(long long i=kk;i<=n-1;i++)
        {
            t2=a[i+1];
            a[i+1]=t1;
            t1=t2;
        }
        a[kk]=ks;
    }
    for(long long i=1;i<=n;i++)
    {
        k=1;
        while(mt>=0)
        {
            b[i]++;
            if(i+k>n)
                mt=-1;
            de=a[i+k]-a[i-1+k];
            mt=mt-de*k;
            k++;
        }
        mt=m;
    }
    maxn=-1;
    for(long long i=1;i<=n;i++)
    {
        if(b[i]>maxn)
            maxn=b[i];
    }
    cout<<maxn;
    return 0;
}
