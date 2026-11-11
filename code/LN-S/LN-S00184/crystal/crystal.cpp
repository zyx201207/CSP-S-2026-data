#include <bits/stdc++.h>
using namespace std;
unsigned long long n,m;
long long a[500005];
unsigned long long use[500005]={0};
long long ans=1;
bool cmp(long long a,long long b)
{

    return a>b;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n>5000)
    {

        sort(a,a+n);
        for (long long  i=1;i<n;i++)
        {
            use[i]+=use[i-1]+a[i-1];
            if(m<use[i])
            {
                ans=i;
                break;
            }

        }
        cout<<ans;
    }
    else
    {
        sort(a+1,a+n+1);
        for (long long  i=2;i<=n;i++)
        {
            use[i]=use[i-1]+(i-1)*(a[i]-a[i-1]);
            if(m<use[i])
            {
                cout<<i-1;
                break;
            }
        }
    }

    return 0;
}
