#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long a[200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long maxn=-99;
    for(int i=1;i<=n;i++)
    {
        long long b=a[i];
        bool c[200005];
        for(int i=1;i<=n;i++)
        {
            c[i]=0;
        }
        int d=1;
        for(int j=i+1;j<=n;j++)
        {
            if(c[j]==1) continue;
            if(d==m) break;
            b=(b&a[j]);
            d++;
            c[j]=1;
            if(b>=maxn)
            {
                maxn=b;
            }
        }
    }
    cout<<maxn;
    return 0;
}
