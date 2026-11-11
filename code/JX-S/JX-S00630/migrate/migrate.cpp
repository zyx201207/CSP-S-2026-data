#include <bits/stdc++.h>
using namespace std;
int c,t,n,tu[5010][5010],can[5010][5010],zx[5010][5010];
long long a[2000100],d;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t)
    {
        t--;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        long long ans=0,l=1,r=1;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                tu[i][j]=0;
                can[i][j]=0;
                zx[i][j]=1e7;
            }

        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[j]-a[i]>d) break;
                tu[i][j]=1;
                can[i][j]=1;
                zx[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=i+1;k<=j-1;k++)
                {
                    if(zx[i][j]==zx[i][k]+zx[k][j])
                    {
                        can[i][j]+=can[i][k]*can[k][j];
                    }
                    else if(zx[i][j]>zx[i][k]+zx[k][j])
                    {
                        zx[i][j]=zx[i][k]+zx[k][j];
                        can[i][j]=1;
                    }
                }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(can[i][j]==2)
                    ans++;
        cout<<ans<<'\n';
    }
    return 0;
}
