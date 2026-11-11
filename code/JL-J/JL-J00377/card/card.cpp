#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,c;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
       cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[j]==i)
            {
                cout<<j;
            }
        }

    }
}
