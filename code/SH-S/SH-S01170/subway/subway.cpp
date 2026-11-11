#include<bits/stdc++.h>
#define int long long
using namespace std; 

const int N=2e5+5e4+5;
const int inf=2e9+5;

int route[N];

int c,n,m,d,q;
int w[N],k[N];

int as=inf;

struct imf{
	int a;
	int t;
};

imf a[N][505];
bool vis[505];

void dfs(int x,int y,int sum,int ty)
{
	int turn=0;
	for(int i=1;i<=k[x];i++)
	{
		if(a[i][x].a==x)
		{
			turn=a[i][x].t;
		}
	}
	route[ty]=x;
	vis[x]=1;
	if(x==y)
	{
//		for(int i=1;i<=ty;i++)
//		{
//			cout<<route[i]<<' ';
//		}
//		cout<<'\n';
//		cout<<as<<'\n';
//		cout<<sum<<'\n';
		as=min(as,sum);
		return ;
	}
	for(int i=1;i<=k[x];i++)
	{
		if(a[i][x].a==x)
		{
			sum+=turn;
		}
		if(!vis[a[i][x].a])
		{
			vis[a[i][x].a]=1;
			dfs(a[i][x].a,y,sum+a[i][x].t,ty+1);
			vis[a[i][x].a]=0;
		}
	}
}

void solve(int x,int y)
{
	as=inf;
	memset(vis,0,sizeof(vis));
	dfs(x,y,0,1);
	as+=w[x]+w[y];
	cout<<as<<'\n';
}

signed main()
{
	freopen("subway.in","r",stdin);	
	freopen("subway.out","w",stdout);	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[j][i].a>>a[j][i].t;	
		}
	}
//	cout<<"basic imput is over"<<'\n';
	int st,ed;
	for(int i=1;i<=q;i++)
	{
		cin>>st>>ed;
		solve(st,ed);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
