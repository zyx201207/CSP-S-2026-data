#include <bits/stdc++.h>
using namespace std;
const int N=2000005;
int C,T,n;
long long d,ans;
long long X[N];
vector<int> edge[N];
struct node{
	int pos,len;
	node(){}
	node(int a,int b):pos(a),len(b){}
};
int min_path[N],num[N];

void bfs(int st)  //找最短路 
{
	memset(min_path,-1,sizeof(min_path));
	queue<node> qu;
	qu.push(node(st,0));
	while(!qu.empty())
	{
		int u=qu.front().pos,l=qu.front().len;  qu.pop();
		for(int i=0;i<edge[u].size();++i)
		{
			int v=edge[u][i];
			if(min_path[v]==-1||l+1<min_path[v])
			{
				num[v]=1;
				min_path[v]=l+1;
			}
			else if(l+1==min_path[v])
			{
				num[v]++;
				if(num[v]==2)  ans++;
				if(num[v]==3)  ans--;
			}
			qu.push(node(v,l+1));
		}
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i)  edge[i].clear();
		for(int i=1;i<=n;++i)
		{
			cin>>X[i];
		}
		long long delta;
		for(int i=1;i<=n-1;++i)  //建图 
		{
			for(int j=i+1;j<=n;++j)
			{
				delta=X[j]-X[i];
				if(delta<=d)
				{
					edge[i].push_back(j);
				}
				else  break;
			}
		}
		for(int i=1;i<=n-1;++i)  //找最短路 
		{
			memset(num,0,sizeof(num));
			bfs(i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

