#include <bits/stdc++.h>
using namespace std;
int main()
{   freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a[200005],d=0;
    char b[200005];
    cin>>n;
    for(int i=1;i<=n;i++)
    {   cin>>a[i]>>b[i];
    }
    for(int i=1;i<=(n+1)/2;i++)
    {   int e=n+1-i;
        if(i==e)
        {   continue;
        }
        if(b[i]!=b[e])
        {   d+=min(a[i],a[e]);
        }
        if(a[i]!=a[e])
        {   d+=abs(a[i]-a[e]);
        }
    }
    cout<<d;
    return 0;
}
