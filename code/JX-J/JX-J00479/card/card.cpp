#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[500005],z[500005],top=1;
bool vis[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        top=1;
        for(int j=1;j<=n;j++)
        {
            z[j]=0;
            vis[j]=0;
        }

        for(int j=i;j<=n;j++)
        {
            if(vis[a[j]]==1)
            {
                while(z[top]!=a[j])
                {
                    vis[z[top]]=0;
                    z[top--]=0;
                }

                z[top--]=0;
                z[++top]=a[j];
            }
            else{
                z[++top]=a[j];
                vis[a[j]]=1;
            }
        }
        for(int k=1;k<=top;k++)
            sum[z[k]]++;
    }
    for(int i=1;i<=m;i++)
       cout<<sum[i]<<' ';
    return 0;
}
