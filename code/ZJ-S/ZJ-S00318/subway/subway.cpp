#include<bits/stdc++.h>
using namespace std;
const int M=405;
const int N=205;
struct node{
	int v;
	long long w;
	bool operator<(const node &x)const{
		return w>x.w;
	}
};
long long de[M],w[M],a[N][M],t[N][M];
priority_queue<node> q;
vector<int> b[M];
bool vis[M];
int k[N];
void dij(int s)
{
	int u,i,j,len,x;
	node tmp;
	memset(de,0x3f,sizeof(de));
	memset(vis,false,sizeof(vis));
	de[s]=0;
	tmp.v=s;
	tmp.w=0;
	q.push(tmp);
	while(!q.empty())
	{
		u=q.top().v;
		q.pop();
		if(vis[u]==true)
		{
			continue;
		}
		for(i=0;i<b[u].size();i++)
		{
			len=k[b[u][i]];
			for(j=0;j<=len;j++)
			{
				if(a[b[u][i]][j]==u)
				{
					x=j;
					break;
				}
			}
			for(j=0;j<=len;j++)
			{
				if(a[b[u][i]][j]==u)
				{
					continue;
				}
				if(de[a[b[u][i]][j]]>t[b[u][i]][x]+de[u]+t[b[u][i]][j])
				{
					de[a[b[u][i]][j]]=t[b[u][i]][x]+de[u]+t[b[u][i]][j];
					tmp.v=a[b[u][i]][j];
					tmp.w=de[a[b[u][i]][j]];
					q.push(tmp);
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q,i,j,u,v;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>k[i];
		for(j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			b[a[i][j]].push_back(i);
		}
	}
	while(q--)
	{
		cin>>u>>v;
		dij(u);
		cout<<w[u]+de[v]+w[v]<<"\n";
	}
	return 0;
}