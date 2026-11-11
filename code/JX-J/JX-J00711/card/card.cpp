#include<bits/stdc++.h>
using namespace std;
long long n,nn,m,a[500010],b[500010],c[500010],ci=0;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        b[a[i]]=i;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<b[m]<<' ';
    }
    return 0;
}
