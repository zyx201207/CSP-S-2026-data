#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,p;
long long w[500005]={};
long long a[500005]={};
long long k[500005]={};
long long v[500005]={};
long long x[500005]={};
long long y[500005]={};
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i];
        }
        for(int j=1;j<=k[i];j++)
        {
            cin>>k[i];
        }
    }
    for(int i=1;i<=p;i++)
    {
        cin>>x[i];
        cin>>y[i];
    }
    for(int i=1;i<=p;i++)
    {

    }
}
