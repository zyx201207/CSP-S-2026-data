#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define int long long
vector<int>vc[5000005];
vector<int>bq[5000005];
int a[100005],b[100005],c[100005],dis[5000005];
void bfs(int x)
{
	memset(dis,0x3f,sizeof(dis));
	queue<int>q;
	dis[x]=0;
	q.push(x);
	while(!q.empty())
	{
		int xx=q.front();
		q.pop();
		for(int i=0;i<vc[xx].size();i++)
		{
			if(dis[vc[xx][i]]>dis[xx]+bq[xx][i])
			{
				dis[vc[xx][i]]=dis[xx]+bq[xx][i];
				q.push(vc[xx][i]);
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int cc,n,m,d,t;
	cin>>cc>>n>>m>>d>>t;
	int cur=m;
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		cur++;
		vc[i].push_back(cur);
		vc[cur].push_back(i);
		bq[i].push_back(x);
		bq[cur].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		int l=0;
		int o;
		cin>>o;
		for(int j=1;j<=o;j++)
		{
			int x,y;
			cin>>x>>y;
			cur++;
			vc[x+m].push_back(cur);
			vc[cur].push_back(x+m);
			bq[x+m].push_back(y);
			bq[cur].push_back(y);
			if(l)
			{
				vc[l].push_back(cur);
				vc[cur].push_back(l);
				bq[l].push_back(0);
				bq[cur].push_back(0);
			}
			l=cur;
		}
	}
	for(int i=1;i<=t;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=m;i++)
	{
		bfs(i);
		for(int j=1;j<=t;j++)
			if(a[j]==i)
				c[j]=dis[b[j]];
	}
	for(int i=1;i<=t;i++)
		cout<<c[i]<<endl;
}