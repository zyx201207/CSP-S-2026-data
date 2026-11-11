#include<bits/stdc++.h>
using namespace std;
long long a[100000010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n=0,m=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long k=m;
    long long mx=0;
    long long x=0;
    long long y=0;
    long long pl=0;
    long long ans=0;
    sort(a,a+n);
    for(int i=a[0];i<a[n-1];i++)
    {
        x=i;
        k=m;
        while(k)
        {
            for(int j=0;j<n;j++)
            {
                y=x-a[j];
                if(a[j]<=x && a[j]+y==x && k-y>0)
                {
                    pl++;
                    k-=y;
                }
            }
            if(pl==n)
            {
                ans=min(ans,x);
            }
        }
    }
    int i=0;
    while(m)
    {
        mx++;
        m=m-(x-a[i]);
        i++;
    }
    cout<<mx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
