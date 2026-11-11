#include<bits/stdc++.h>
using namespace std;
const int MAXN=500001;
long long head[MAXN];
struct node{
	int to,w,next;
}edge[MAXN];
int cnt=1;
int c,n,m,d,q;
int w[MAXN];
vector<int> tlst[501][2];
void add(int u,int v,int w)
{
	edge[u].w=w;
	edge[u].to=v;
	edge[u].next=head[u];
	head[u]=cnt;
	cnt++;
}
void input()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
		tlst[i][0].push_back(tmp);
		tlst[i][1].push_back(0);
		for(int j=1;j<=tlst[i][0][0];j++)
		{
			cin>>tmp;
			tlst[i][0].push_back(tmp);
			cin>>tmp;
			tlst[i][1].push_back(tmp);
		}
	}
}
void process()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<tlst[i][0][0];j++)
		{
			cout<<10;
			for(int k=j+1;k<=tlst[i][0][0];k++)
			{
				cout<<1;
				add(tlst[i][j][0],tlst[i][k][0],tlst[i][j][1]+tlst[i][k][1]);
				add(tlst[i][k][0],tlst[i][j][0],tlst[i][j][1]+tlst[i][k][1]);
			}
		}
	}
	cout<<2;
	return;
}

void small()
{
	int x,y;
	int ans=0;
	cin>>q;
	while(q--)
	{
		cin>>x>>y;
		int dij[301][301];
		memset(dij,0x7f,sizeof(dij));
		for(int i=1;i<=n;i++)
		{
			for(int j=head[i];j!=-1;j=edge[j].next)
			{
				int v=edge[j].to;
				dij[i][v]=edge[j].w;
				for(int k=1;k<=n;k++)
				{
					if((k!=i)&&(k!=v))dij[k][v]=min(dij[k][v],dij[k][i]+dij[i][v]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<dij[i][j]<<" ";
			}
			cout<<endl;
		}
		//cout<<dij[x][y]+w[x]+w[y]<<endl;
	}
	return;
}
void aaa()
{
	for(int i=1;i<=n;i++)
	{
		add(tlst[i][1][0],tlst[i][2][0],tlst[i][1][1]+tlst[i][2][1]);
		add(tlst[i][2][0],tlst[i][1][0],tlst[i][1][1]+tlst[i][2][1]);
	}
	int dij[1001][1001];
	
	return;
}
void bbb()
{
	cin>>q;
	while(q--)
	{
		cout<<0<<endl;
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof(head));
	input();
	if((c>=0)&&(c<=6))
	{
		process();
		small();
	}
	else if((c>=7)&&(c<=11))
	{
		aaa();//c为边数 
	}
	else if((c>=12)&&(c<=19))
	{
		bbb();//边长均相同 
	}
	else
	{
		cin>>q;
		while(q--)
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
