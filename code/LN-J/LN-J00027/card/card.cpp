#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ga[500005];
bool ca[300005];
int ans[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,j1,g=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int nu=1;nu<=m;nu++)
        {
            ca[nu]=0;
        }
        g=1;
        for(int j=i;j<=n;j++)
        {
            if(ca[a[j]]==0)
            {
                ca[a[j]]=1;
                ga[g]=a[j];
                g++;
            }
            else if(ca[a[j]]==1)
            {
                for(int k=g-1;k>=1;k--)
                {
                    g--;
                    if(ga[k]==a[j])
                    {
                        g++;
                        break;
                    }
                    ca[ga[k]]=0;
                    ga[k]=0;
                }
            }
            if(j==n)
            {
                for(int k=1;k<=g;k++)
                {
                    ans[ga[k]]++;
                }
                for(int k=1;k<=n;k++)
                {
                    ga[k]=0;
                }
                break;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
