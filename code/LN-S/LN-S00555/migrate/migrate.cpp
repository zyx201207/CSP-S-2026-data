#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t;
ll n,d;
int dis[5005][5005];
int zou[5005][5005];
int a[5005];
int ans;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    memset(dis,0,sizeof(dis));
    while(t--)
    {
        cin>>n>>d;
        int cha=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(i>1)
            {
                dis[i-1][i]=a[i]-a[i-1];
                if(dis[i][i-1]<=d)
                {
                    zou[i][i-1]=1;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                dis[i][j]=a[j]-a[i];
                if(dis[i][j]<=d)
                {
                    zou[i][j]=1;
                    if(j-i==2) ans++;
                }
                else
                {
                    zou[i][j]=0;
                    int f=1;
                    for(int k=i+1;k<=j;k++)
                    {
                        if(dis[k][k-1]>d)
                        {
                            f=0;
                        }

                    }
                    if(f==1)
                    {
                        for(int k=i+1;k<=j;k++)
                        {
                            if(zou[k][j]==1)
                            {
                                ams++;
                            }
                        }
                    }
                }

            }
        }
        cout<<ans;
    }
    return 0;
}
