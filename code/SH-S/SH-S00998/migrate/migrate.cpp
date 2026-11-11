#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5009;
int n,d;
ll x[2000006];
ll ans;
ll e[N][N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    int C,T;
	cin>>C>>T;
    while(T--)
    {
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++)cin>>x[i];
        sort(x+1,x+1+n);
        memset(e,-1,sizeof(e));
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(x[j]<=x[i]+d)e[i][j]=0;
                else if(lower_bound(x+1,x+1+n,x[j]-d)-x>upper_bound(x+1,x+1+n,x[i]+d)-x-1)e[i][j]=-1;
                else if(lower_bound(x+1,x+1+n,x[j]-d)-x==upper_bound(x+1,x+1+n,x[i]+d)-x-1)e[i][j]=1;
                else if(lower_bound(x+1,x+1+n,x[j]-d)-x+1==upper_bound(x+1,x+1+n,x[i]+d)-x-1)e[i][j]=2,ans++;
                else e[i][j]=3;
            }
        }
        for(int i=1;i<=n;i++)
          for(int j=i+1;j<=n;j++)
            {
                if(e[i][j]!=-1)continue;
                for(int k=i+1;k<=j-1;k++)
                {
                    if((e[i][k]==0||e[i][k]==1)&&(e[k][j]==0||e[k][j]==1))e[i][j]=1;
                    else if((e[i][k]==1&&e[k][j]==2)||(e[i][k]==2&&e[k][j]==1))e[i][j]=2,ans++;
                    else if(e[i][k]>=2&&e[k][j]>=2)e[i][j]=3;
                }
            }
        cout<<ans<<endl;
    }
	return 0;
}
