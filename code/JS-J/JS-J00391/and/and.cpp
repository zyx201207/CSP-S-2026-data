#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],maxn;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(m==n)
    {
        maxn=a[1];
        for(int i=2;i<=n;i++)
            maxn&=a[i];
    }
    if(m==1)
        for(int i=1;i<=n;i++)
            maxn=max(maxn,a[i]);
    if(m==2)
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                maxn=max(maxn,a[i]&a[j]);
    if(m==n-1)
        for(int i=1;i<=n;i++)
        {
            if(i==1)
            {
                maxn=a[2];
                for(int j=3;j<=n;j++)
                    maxn&=a[i];
            }
            else
            {
                maxn=a[1];
                for(int j=2;j<=n;j++)
                {
                    if(j==i)
                        continue;
                    else
                        maxn&=a[i];
                }
            }
        }
    cout<<maxn;
}
