#include<bits/stdc++.h>
using namespace std;
char s[1000000000];
char p[1000000000];
long long a[1000000000];
long long n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdin);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>s[i];
    }
    long long z=0;
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=a[i];j++)
        {
            z++;
            p[z]=s[i];
        }
    }
    for(long long i=1;i<=p.size;i++)
    {
        for(long long j=sqrt(size.p());j>=1;j--)
        {
            z++;
            p[z]=s[i];
        }
    }
}
