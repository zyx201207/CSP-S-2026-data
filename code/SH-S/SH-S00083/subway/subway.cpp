#include <bits/stdc++.h>
using namespace std;
const int N=505,M=500005;
int C,n,m,d,q;
long long ans=1e18;
int w[M];
vector<int> T[N];
struct Edge{
	int To,type;
	Edge(){}
	Edge(int a,int b):To(a),type(b){} 
};

vector<Edge> edge[M];
struct node{
	int pos,line;
	long long len;
	node(){}
	node(int a,int b,long long c):pos(a),line(b),len(c){} 
};

void bfs(int st,int ed)
{
	queue<node> qu;
	qu.push(node(st,st,0));
	while(!qu.empty())
	{
		int u=qu.front().pos,Line=qu.front().line;
		long long l=qu.front().len;  
		qu.pop();
		if(u==ed)  {ans=min(ans,l);}
		for(int i=0;i<edge[u].size();++i)
		{
			int v=edge[u][i].To,Type=edge[u][i].type;
			if(Type!=Line)  l+=T[u][u]+T[u][v];
			else  l+=T[u][v];
			qu.push(node(v,Type,l));
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
	}
	int k,tmp1,tmp2;
	for(int i=1;i<=n;++i)
	{
		cin>>k;
		T[i].push_back(0);
		for(int j=1;j<=k;++j)
		{
			cin>>tmp1>>tmp2;
			if(tmp1!=i)  edge[i].push_back(Edge(tmp1,i));
			T[i].push_back(tmp2);
		}
	}
	int x,y;
	while(q--)
	{
		ans=1e18;
		cin>>x>>y;
		bfs(x,y);
		ans+=1ll*(w[x]+w[y]+T[x][x]);
		cout<<ans<<'\n';
	}
	return 0;
}

