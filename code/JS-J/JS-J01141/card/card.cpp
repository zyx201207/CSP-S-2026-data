#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int p=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<a[i-1]) p=0;
    }
    if(p)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                b[a[j]]++;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cout<<b[i]<<" ";
        }

    }
    return 0;
}
