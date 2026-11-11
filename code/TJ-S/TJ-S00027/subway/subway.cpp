#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=505;
int c,n,m,d,q,w[N];
bool is_check[N+M];
struct node
{
	int to,val;
};
vector <node> edge[N+M];
int dfs(int x,int y,int father)
{
	int minn=0x3f3f3f3f;
	if(edge[x].size()==1&&father!=0)return minn;
	for(int i=0;i<edge[x].size();i++)
	{
		if(edge[x][i].to==father)continue;
		if(edge[x][i].to==y)return edge[x][i].val;
		minn=min(minn,edge[x][i].val+dfs(edge[x][i].to,y,x));
	}
	return minn;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,x;i<=n;i++)
	{
		cin>>x;
		for(int j=1,y,z;j<=x;j++)
		{
			cin>>y>>z;
			node temp;temp.to=y;temp.val=z;
			edge[i+500000].push_back(temp);
			temp.to=i+500000;
			edge[y].push_back(temp);
		}
	}
	for(int i=1,x,y;i<=q;i++)
	{
		cin>>x>>y;
		cout<<w[x]+w[y]+dfs(x,y,0)<<endl;
	}
	return 0;
}

