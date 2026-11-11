#include <bits/stdc++.h>

using namespace std;
struct node
{
    long long a;
    char c;
}s[200005];
long long sum[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ant=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].a>>s[i].c;
        sum[i]=sum[i-1]+s[i].a;
    }
    long long j=1;
    long long z=1;
    long long m=sum[n];
    long long h=n;
    for(long long i=sum[n];i>=1;i--)
    {
        if(i==j||j>i)
        {
            break;
        }
        if(j>sum[z])
        {
            z++;
        }
        if(m==sum[h-1])
        {
            h=h-1;
            m=sum[h];
        }
        if(s[z].c!=s[h].c)
        {
            ant++;
        }
        j++;
    }
    cout<<ant;
    return 0;
}
