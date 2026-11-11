#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,w[N],a[510][510],num[510];
struct node{
	int id,val;
};
vector<node>vec[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		for(int j=1;j<=num[i];j++)
		{
			int x,val;
			cin>>x>>val;
			vec[x].push_back(node{i,val});
		}
	}
	memset(a,63,sizeof(a));
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<vec[i].size();i++)
		{
			for(int k=j+1;k<vec[i].size();k++)
			{
				a[vec[i][j].id][vec[i][k].id]=min(a[vec[i][j].id][vec[i][k].id],vec[i][j].val+vec[i][k].val);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		a[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=min(a[i][j],a[j][i]);
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				a[j][i]=min(a[j][i],a[i][j]);
			}
		}
	}
	while(q--)
	{
		int x,y,ans=LLONG_MAX;
		cin>>x>>y;
		for(int i=0;i<vec[x].size();i++)
		{
			for(int j=0;j<vec[y].size();j++)
			{
				ans=min(ans,vec[x][i].val+vec[y][j].val+w[x]+w[y]+a[vec[x][i].id][vec[y][j].id]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0; 
} 
