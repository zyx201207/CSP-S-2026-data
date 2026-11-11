#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200100],t=0,ma=-1,l=1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ma=max(a[i],ma);
    }
    for(int i=30;i>=0;i--)
    {
        int f=0;
        sort(a+l,a+n+1);
        long long p=pow(2,i);
        for(int j=n;j>=l;j--)
        {
            if(a[j]<p)
            {
                f=1;
                if(n-j>=k)
                {
                    t+=p;
                    l=j+1;
                }
                break;
            }
            a[j]-=p;
        }
        if(f==0)
        {
            t+=p;
        }
    }
    cout<<t;
    return 0;
}
