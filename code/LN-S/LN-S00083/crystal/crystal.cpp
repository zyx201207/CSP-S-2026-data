#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxn;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long i=1;
    while(m>0||i<=n)
    {
        if(a[i]!=a[i+1]&&m>=a[i+1]-a[i])
        {
            m-=a[i+1]-a[i];
            a[i]=a[i+1];
            i=1;
        }
        else if(m<a[i+1]-a[i])
        {
            maxn=max(i,maxn);
            break;
        }
        else
        {
            i++;
        }
    }
    if(i>1)
    {
        maxn=max(maxn,i);
    }
    cout<<maxn;
    return 0;
}

