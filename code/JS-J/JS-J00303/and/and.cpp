#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,k=0,t=100000000000,p=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(k<a[i]) k=a[i];
        }
        cout<<k;
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[i]&a[j]>k) k=a[i]&a[j];
            }
        }
        cout<<k;
    }
    else if(m==n-1)
    {
        k=pow(2,21);
        k--;
        for(int i=1;i<=n;i++)
        {
            if(t>a[i]&k)
            {
                t=a[i]&k;
                p=i;
            }
        }
        for(int i=1;i<p;i++)
        {
           k=k&a[i];
        }
        for(int i=p+1;i<=n;i++)
        {
            k=k&a[i];
        }
        cout<<k;
    }
    else
    {
        k=pow(2,21);
        k--;
        sort(a+1,a+n+1);
        for(int i=n;i>n-m;i--)
        {
            k=k&a[i];
        }
        cout<<k;
    }
    return 0;
}
