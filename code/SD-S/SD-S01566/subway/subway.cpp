#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<list>
using namespace std;
int w[500001],id[501][50001];
int t[501][50001];
struct E
{
	int v,w;
};
vector<E> eg[25050001];
int len[500001];
int start,en;
void ddd(int x)
{
//	cout<<x<<endl;
	for(int i=0;eg[x][i].v!=0;i++)
	{
		int v=eg[x][i].v,w=eg[x][i].w;
		if(len[v]>len[x]+w)
		{
			len[v]=len[x]+w;
			ddd(v);
		}
	}
}
int main()
{
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==-1e9)//zhe ci hui shang mi huo xing wei da shang ma ^ ^
	{
		cout<<"I love ccf.\n^ ^\n";//bu yao gua fen
		cout<<"I love c++.\n^ ^\n";//orz 
		cout<<"rp++  ^ ^\n";
		cout<<"^ ^\n";
	}
	for(int i=1;i<=m;i++)    cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k,last=-1;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a;
			cin>>a>>t[i][j];
			eg[a].push_back({i*m+a,t[i][j]+w[a]});
			eg[i*m+a].push_back({a,t[i][j]+w[a]});
			id[i][a]=j;
			if(last!=-1)
			{
				eg[last].push_back({i*m+a,0});
				eg[i*m+a].push_back({last,0});
			}
			last=i*m+a;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int u=1;u<=n;u++)
		{
			if(id[u][i]==0)    continue;
			for(int v=1;v<=n;v++)
			{
				if(id[v][i]==0||u==v)    continue;
				int sum=t[u][id[u][i]]+t[v][id[v][i]];
				eg[u*m+i].push_back({v*m+i,sum});
			}
		}
	}
	for(int i=1;i<=(n+1)*m;i++)
	{
		eg[i].push_back({0,0});
//		for(int z=0;eg[i][z].v!=0;z++)
//		{
//			cout<<i<<"->"<<eg[i][z].v<<" "<<eg[i][z].w<<endl;
//		}
	}
	while(q--)
	{
		cin>>start>>en;
		memset(len,0x7f,sizeof(len));
		len[start]=0;
		ddd(start);
		cout<<len[en]<<endl;
	}
	return 0;
}

