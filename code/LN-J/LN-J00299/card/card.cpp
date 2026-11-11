#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("caed.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n+5],b[m+5];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]=i;

    }
    for(int i=1;i<=m;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}
