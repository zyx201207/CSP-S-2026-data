#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5005;
int n,c,T,d,x[N],dp[N][N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;int ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];dp[i][i]=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j-1;k>=i;k--)
				{
					//cout<<k<<" "<<x[k]<<" "<<j<<" "<<x[j]<<endl;
					if(x[k]+d>=x[j])
					{
						dp[i][j]+=dp[i][k];
						//cout<<"AAA"<<endl;
						continue;
					}
					break;
				}
				//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
				if(dp[i][j]==2) ans++;
			}
		}
		cout<<ans<<endl;
		memset(dp,0,sizeof(dp));
	}
	return 0;
}
//今年又只有二等了 