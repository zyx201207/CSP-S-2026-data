#include <bits/stdc++.h>
#define int long long
#define ul unsigned long long
#define inf 1e18

using namespace std;
int p[510];
int num[510];
int cnt[510];
bool vis[510];
void solve()
{
	vector<int>g[510];
	int ans=0;
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(p[j]-p[i]<=d)g[i].push_back(j);
			else break;
		}
	}
	for(int st=1;st<=n;st++)
	{
		for(int j=1;j<=n;j++)num[j]=0x3f3f3f3f,cnt[j]=vis[j]=0;
		queue<pair<int,int>>q;
		q.push({st,0});
		while(!q.empty())
		{
			int t=q.front().first;
			int w=q.front().second;
			q.pop();
//			cout<<t<<' '<<w<<endl;
			for(auto to:g[t])
			{
				if(num[to]>=w+1)q.push({to,w+1});
				if(num[to]==w+1)cnt[to]++;
				if(num[to]>w+1)cnt[to]=1,num[to]=w+1;
			}
			
//		for(int i=st;i<=n;i++)if(cnt[i]==2)cout<<i<<' ';
		}
		for(int i=st;i<=n;i++)if(cnt[i]==2)ans++;
//		cout<<st<<endl;for(int i=st;i<=n;i++)cout<<cnt[i]<<' '<<num[i]<<' '<<endl;
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

