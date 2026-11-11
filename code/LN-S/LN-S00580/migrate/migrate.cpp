#include<bits/stdc++.h>
using namespace std;

const int N=2e6+5;
int C,T;
long long n,d;
long long x[N];
long long dis[5005][5005];
int cnt[5005][5005];
long long ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--)
    {
        memset(dis,0,sizeof(dis));
        memset(cnt,0,sizeof(cnt));
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=1e18;
            }
            dis[i][i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(abs(x[i]-x[j])<=d)dis[i][j]=1;
                //cout<<i<<' '<<j<<' '<<dis[i][j]<<'\n';
            }
            dis[i][i]=0;
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(i==j)continue;
                    if(dis[i][k]+dis[k][j]<dis[i][j])
                    {
                        dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(cnt[i][j]>2)continue;
                for(int a=1;a<=n;a++)
                {
                    if(dis[a][i]>=1e18||dis[a][j]>=1e18||i==a||j==a)continue;
                    if(dis[i][a]+dis[a][j]==dis[i][j])
                    {
                        cnt[i][j]++;
                        //cout<<i<<"->"<<a<<"->"<<j<<'\n';
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                //cout<<i<<' '<<j<<' '<<cnt[i][j]<<'\n';
                if(cnt[i][j]==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

/*
求你了一定要AC喵
已经无能为力了喵
红紫黑黄的不要喵
芙兰朵露脚香香喵
*/
