#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
#define int long long

int c,n,m,d,q,x,y,minn;
int w[500005],k[505];
vector<int>a[505],t[505];
vector<vector<pair<int,int> > >st;

int graph[505][505];
map<pair<int,int>,int>tab;
inline int read(void)
{
	int num=0;char ch=' ';
	while(!(ch<='9'&&ch>='0'))ch=getchar();
	do{
		num=num*10+(ch-'0');
		ch=getchar();
	}while(ch>='0'&&ch<='9');
	return num;
}

signed main(void)
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(graph,0x3f3f3f3f3f3f3f3f,sizeof(graph));
	cin>>c>>n>>m>>d>>q;
	for(register int i=1;i<=m;i++)
		w[i]=read();
	st.resize(m+1);
	for(register int i=1;i<=n;i++)
		graph[i][i]=0;
	for(register int i=1;i<=n;i++)
	{
		k[i]=read();
		a[i].push_back(0),t[i].push_back(0);
		for(register int j=1;j<=k[i];j++)
		{
			x=read();y=read();
			a[i].push_back(x);
			t[i].push_back(y);
			tab[make_pair(i,x)]=j;
			if(st[x].size()>0)
			{
				for(int z=0;z<st[x].size();z++)
				{
					graph[i][st[x][z].first]=min(st[x][z].second+y,graph[i][st[x][z].first]);
					graph[st[x][z].first][i]=graph[i][st[x][z].first];
				}
			}
			st[x].push_back(make_pair(i,y));
		}
	}
	for(register int k=1;k<=n;k++)
	{
		for(register int i=1;i<=n;i++)
		{
			if(i==k)continue;
			for(register int j=1;j<=n;j++)
			{
				if(i==j||j==k)continue;
				if(graph[i][k]+graph[k][j]<graph[i][j])
					graph[i][j]=graph[i][k]+graph[k][j];
			}
		}
	}
	while(q--)
	{
		x=read();y=read();
		minn=0x3f3f3f3f3f3f3f3f;
		for(register int i=0;i<st[x].size();i++)
			for(register int j=0;j<st[y].size();j++)
			{
				minn=min(graph[st[x][i].first][st[y][j].first]+t[st[x][i].first][tab[make_pair(st[x][i].first,x)]]+t[st[y][j].first][tab[make_pair(st[y][j].first,y)]],minn);
			}
		printf("%lld\n",w[x]+w[y]+minn);
	}
}