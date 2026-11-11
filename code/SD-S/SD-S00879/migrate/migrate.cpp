#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=310;
const ll INF=1e18;
ll a[N];
map<pair<ll,ll>,int> mp;
int n;
long long d;
bool can[N][N];
void init()
{
	memset(can,0,sizeof(can));
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if (a[j]-a[i]<=d) can[i][j]=1;
		}
	}
}
void floyd()
{
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			can[i][i]=1;
			for (int j=i+1;j<=n;j++)
			{
				if (a[j]-a[i]<=d) continue;
				if (can[i][k] && can[k][j] && i!=k && k!=j)
				{
					mp[{i,j}]++;
					can[i][j]=1;
				}
			}
		}
	}
}
int solve()
{
	int cnt=0;
	for (int i=1;i<=n-3;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if (a[j]-a[j-1]>d) break;
			if (mp[{i,j}]==2 && j>=i+3) cnt++;
		}
	}
	return cnt;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--)
	{
		mp.clear();
		cin>>n>>d;
		bool flag=1;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
			if (i>2 && a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=0;
		}
		if (flag)
		{
			if (a[2]-a[1]<d)
			{
				cout<<0<<"\n";
			}
			else cout<<2LL*(ll)(n-3)<<"\n";
			continue;
		}
		init();
		floyd();
		cout<<solve()<<"\n";
	}
	return 0;
}
