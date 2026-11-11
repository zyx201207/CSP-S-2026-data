#include<bits/stdc++.h>
using namespace std;
long long a[100000];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,maxn=-100000;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
    {
        long long b=1,M=m;
        while(m!=0&&b<n&&M>a[i]-a[i-b])
        {
            M=M-(a[i]-a[i-b]);
            a[i-b]=a[i];
            b++;
        }
        if(maxn<b+1)
        {
            maxn=b+1;
        }
        b=1;
        M=m;
    }
    /*int q=0;
    if(m==0)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;i++)
            {
                //if(i)
            }
        }
    }*/
    cout<<maxn;
    return 0;
}
