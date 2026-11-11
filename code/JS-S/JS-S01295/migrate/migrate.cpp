#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Inf=1e18;
int number,T,n,d;
int a[2000005];
int dis[5005][5005],num[5005][5005];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>number>>T;
    while(T--)
    {
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                dis[i][j]=Inf,num[i][j]=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(n<=5000)
        {
            for(int i=2;i<=n;i++)
            {
                for(int j=i-1;j>0;j--)
                {
                    if(a[i]-a[j]<=d)
                    {
                        dis[j][i]=1;
                        num[j][i]=1;
                        continue;
                    }
                    int mi=Inf,cnt=0;
                    for(int k=j+1;k<i;k++)
                    {
                        if(a[k]-a[j]>d)break;
                        if(1+dis[k][i]==mi)cnt+=num[k][i];
                        else if(1+dis[k][i]<mi)
                        {
                            mi=1+dis[k][i];
                            cnt=num[k][i];
                        }
                    }
                    dis[j][i]=mi;
                    num[j][i]=cnt;
                    if(cnt==2)ans++;
                }
            }
            cout<<ans<<'\n';
            continue;
        }
    }
    return 0;
}
