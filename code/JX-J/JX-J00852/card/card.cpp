#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[10005],b[10005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        if(i==a[n])
            b[i]=n;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;i++)
        {
            if(i==a[j] && i!=a[n])
                b[i]+=1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}
