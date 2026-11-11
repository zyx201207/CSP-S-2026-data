#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,n,m,d,q;
vector<int>q1;
int w[500050];
int a[21][500050],t[21][500050];
int x,y;
int vis[21][500050];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
			vis[a[i][j]][i]=1;
		}
	}
	while(q--)
	{
		cin>>x>>y;
		int op=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[x][i]==1)
			{
				op=i;
				break;
			}
		}
		int ans=0;
		for(int i=1;i<=1000000;i++)
		{
			if(a[op][i]==x)
			{
				ans+=t[op][i];
				break;
			}
		}
		for(int i=1;i<=1000000;i++)
		{
			if(a[op][i]==y)
			{
				ans+=t[op][i];
				break;
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
