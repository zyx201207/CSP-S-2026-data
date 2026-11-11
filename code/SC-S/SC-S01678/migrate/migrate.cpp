#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int n,d,x[N];

int f[N],g[N];

int C,T;
void solve1()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			f[j]=1e18;
			g[j]=0;
		}
		
		f[i]=0;
		g[i]=1;
		for(int j=i;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(x[k]-x[j]>d)break;
				if(f[k]>f[j]+1)
				{
					f[k]=f[j]+1;
					g[k]=g[j];
				}
				else if(f[k]==f[j]+1)
				{
					g[k]+=g[j];
				}
			}
			if(g[j]==2)
			{
//				cout<<i<<" "<<j<<"\n";
				ans++;
			}
			else if(C>10&&g[j]>2)break;
		}
	}
	cout<<ans<<"\n";
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--)solve1();
	return 0;
}