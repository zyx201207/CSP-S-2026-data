#include<bits/stdc++.h>
using namespace std;

long long a[200000];
long long s[100001];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<n;i++)cin>>a[i];
    for(long long i=0;i<n;i++)
    {
        long long c[100000]={0};
        long long x=0;
        for(long long j=i;j<n;j++)
        {
            long long k;
            for(k=0;k<x;k++)if(c[k]==a[j])break;
            int y=k;
            for(k;k<x;k++)c[k]=0;
            c[y]=a[j];
            x=y+1;
        }
        for(long long j=0;j<x;j++)s[c[j]]++;
    }
    for(long long i=1;i<=m;i++)cout<<s[i]<<' ';
    return 0;
}
