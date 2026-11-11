#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[1500010];
long long b[1500010];
long long c[1500010];
long long d[1500010];
int qwe=1;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[a[i]]++;
        d[a[i]]=d[a[i]-1]+c[i];
    }
    for(int i=1;i<=m;i++)
    {
        cout<<d[i]-c[i]+1<<' ';
    }
}
