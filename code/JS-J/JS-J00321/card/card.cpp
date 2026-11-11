#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,i;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]=i;
    }
    for(i=1;i<=m;i++)
        cout<<b[i]<<" ";
    return 0;
}
