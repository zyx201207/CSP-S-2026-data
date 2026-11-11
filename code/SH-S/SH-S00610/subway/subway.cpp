
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e18;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m);
	vector<vector<int> > vis(m+1);
	vector<vector<int> > qz(m+1);
	vector<vector<int> > mp(n,vector<int>(n,INF));
	for(int i=0;i<n;i++)
	{
		mp[i][i]=0;
	}
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	int ki;
	int a,t;
	for(int i=0;i<n;i++)
	{
		cin>>ki;
		for(int j=0;j<ki;j++)
		{
			cin>>a>>t;
			vis[a].push_back(i);
			qz[a].push_back(t);
		}
	}
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<vis[i].size();j++)
		{
			for(int k=j+1;k<vis[i].size();k++)
			{
				//cout<<1<<'\n';
				mp[vis[i][j]][vis[i][k]]=min(mp[vis[i][j]][vis[i][k]],qz[i][j]+qz[i][k]);
				mp[vis[i][k]][vis[i][j]]=min(mp[vis[i][k]][vis[i][j]],qz[i][j]+qz[i][k]);
			}
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
				//cout<<mp[i][j]<<'\n';
			}
		}
	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			cout<<mp[i][j]<<" ";
//		}
//		cout<<'\n';
//	}
	int tag1,tag2;
	for(int i=0;i<q;i++)
	{
		cin>>tag1>>tag2;
		int ans=INF;
		for(int j=0;j<vis[tag1].size();j++)
		{
			for(int k=0;k<vis[tag2].size();k++)
			{
				ans=min(ans,mp[vis[tag1][j]][vis[tag2][k]]+qz[tag1][j]+qz[tag2][k]+w[tag1-1]+w[tag2-1]);
				//cout<<mp[vis[tag1][j]][vis[tag2][k]]<<" "<<qz[tag1][j]<<" "<<qz[tag2][k]<<" "<<w[tag1]<<" "<<w[tag2]<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
