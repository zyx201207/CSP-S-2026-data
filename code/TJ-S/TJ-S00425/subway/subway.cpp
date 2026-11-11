#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
const long long inf = 1e18;
struct node
{
	long long ind,t;
};
long long n,m,d,q,edgenum,nowm,nowt,ans;
node newnode;
long long w[500050];
long long a[510][510];
long long dis[510][510];
vector<node> edge[500050];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n;
	cin>>n>>m>>d>>q;
	for(long long i = 1;i <= m;i++)
		cin>>w[i];
	for(long long i = 1;i <= n;i++)
		for(long long j = 1;j <= n;j++)
			a[i][j] = inf;
	for(long long i = 1;i <= n;i++)
	{
		cin>>edgenum;
		for(long long j = 1;j <= edgenum;j++)
		{
			cin>>nowm>>nowt;
			for(long long k = 0;k < edge[nowm].size();k++)
				a[edge[nowm][k].ind][i] = min(a[edge[nowm][k].ind][i],nowt+edge[nowm][k].t);
			newnode.ind = i;
			newnode.t = nowt;
			edge[nowm].push_back(newnode);
		}
	}
	for(long long i = 1;i <= n;i++)
		for(long long j = i+1;j <= n;j++)
			dis[i][j] = dis[j][i] = a[i][j];
	for(long long i = 1;i <= n;i++)
		dis[i][i] = 0;
	for(long long i = 1;i <= n;i++)
		for(long long j = 1;j <= n;j++)
			for(long long k = 1;k <= n;k++)
				dis[j][k] = dis[k][j] = min(dis[j][k],dis[j][i]+dis[i][k]);
	while(q--)
	{
		cin>>nowm>>nowt;
		ans = inf;
		for(long long i = 0;i < edge[nowm].size();i++)
			for(long long j = 0;j < edge[nowt].size();j++)
				ans = min(ans,edge[nowm][i].t+edge[nowt][j].t+dis[edge[nowm][i].ind][edge[nowt][j].ind]);
		cout<<w[nowm]+w[nowt]+ans<<endl;
	}
	return 0;
}
//long long long long
//cin 
