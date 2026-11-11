#include<bits/stdc++.h>
#define maxn 5003
using namespace std;
int c,t;
int n;
long long d;
long long a[maxn];
long long f[maxn][maxn];
int g[maxn][maxn];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            g[i][i]=1;f[i][i]=1;
        }
        int ans=0;
        int kk=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int be=0;
                for(int k=i;k<j;k++)
                {
                    if(a[j]-a[k]>d)
                    {
                        //cout<<"@"<<j<<" "<<k<<"\n";
                        continue;
                    }
                    if(!be)
                    {
                        be=k;
                    }
                    if(g[i][k]!=g[i][be])
                    {
                        break;
                    }
                    //cout<<"!"<<i<<" "<<k<<"\n";
                    f[i][j]+=f[i][k];
                }
                g[i][j]=g[i][be]+1;
                if(f[i][j]==2)
                {
                    ans++;
                }
                if(f[i][j]==0)
                {
                    break;
                }
                kk=max(kk,g[i][j]);
            }
        }
        cout<<ans<<"\n";
        /*for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<f[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";*/
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                //cout<<g[i][j]<<" ";
                f[i][j]=g[i][j]=0;
            }
            //cout<<"\n";
        }
    }
    return 0;
}
