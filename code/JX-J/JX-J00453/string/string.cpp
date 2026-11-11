#include<bits/stdc++.h>
using namespace std;
long long n,t=0;
struct p
{
    long long m;
    char ch;
}a[200100];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i].m>>a[i].ch;
    }
    long long l=1,r=n;
    while(l<r)
    {
        if(a[l].ch!=a[r].ch)
        {
            t+=min(a[l].m,a[r].m);
        }
        if(a[l].m>a[r].m)
        {
            a[l].m-=a[r].m;
            r-=1;
            continue;
        }
        if(a[l].m<a[r].m)
        {
            a[r].m-=a[l].m;
            l+=1;
            continue;
        }
        if(a[l].m==a[r].m)
        {
            l+=1;
            r-=1;
            continue;
        }
    }
    cout<<t;
    return 0;
}
