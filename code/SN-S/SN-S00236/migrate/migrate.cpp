#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
int c, T, n, d, a[maxn], mp[305][305], num[305][305];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(n<=300)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i;j<=n;j++) 
				{
					if(abs(a[i]-a[j])<=d) mp[i][j]=mp[j][i]=num[i][j]=num[j][i]=1;
					else mp[i][j]=mp[j][i]=1e18, num[i][j]=num[j][i]=0;
				}
			}
			for(int k=1;k<=n;k++)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=i+1;j<=n;j++)
					{
						int tmp=mp[i][k]+mp[k][j];
						if(tmp<mp[i][j])
						{
//							cout<<"awa "<<i<<" "<<j<<" "<<k<<endl;
							mp[i][j]=num[j][i]=tmp;
							num[i][j]=num[j][i]=num[i][k]*num[k][j];
						}
						else if(tmp==mp[i][j]) num[i][j]+=num[i][k]*num[k][j], num[j][i]+=num[i][k]*num[k][j];
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
//					cout<<i<<" "<<j<<" "<<mp[i][j]<<" "<<num[i][j]<<endl;
					if(num[i][j]==2) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
