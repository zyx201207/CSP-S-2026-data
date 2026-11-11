#include<bits/stdc++.h>
#define N 5005
#define M 2000005
#define ll long long
using namespace std;
//T3Floyd+特殊性质24~32~44
ll c,t,n,d,x[M],dis[N][N],cnt[N][N];
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<k;i++)
		{
			for(int j=k+1;j<=n;j++)
			{
				if(dis[i][j]==dis[i][k]+dis[k][j])
				{
					cnt[i][j]+=cnt[i][k]*cnt[k][j];
				}
				else if(dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
					cnt[i][j]=cnt[i][k]*cnt[k][j];
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12)//A但是错误 
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>x[i];
			}
			ll ud=x[2]-x[1];
			if(d>=2*ud)
			{
				cout<<n-2<<"\n";
			}
			else
			{
				cout<<"0\n";
			}
		}
		return 0;
	}
	while(t--)
	{
		memset(dis,0x3f,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		ll ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)
				{
					dis[i][j]=cnt[i][j]=1;
				}
			}
		}
		floyd();
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
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
