#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
vector<int> vec[N];
vector<int> dot;
int dx[5+3]={0,1,-1,0,0},dy[5+3]={0,0,0,1,-1},n,k,color[N][N];
void dfs(int nowx,int nowy,int co)
{
	for(int i=1;i<=4;i++)
	{
		int nxtx=nowx+dx[i],nxty=nowy+dy[i];
		if(((nxtx>=1)&&(nxtx<=n))&&((nxty>=1)&&(nxty<=n)))
		{
			dfs(nxtx,nxty,co);
			color[nxtx][nxty]=co;
		}
	}
}
bool check(int x)
{
	int num=0;
	while(x!=0)
	{
		int t=x%2;
		if(t)
		{
			dot.push_back(num);
		}
	}
	int len=dot.size();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dfs(i,j,1);
		}
	}
	return true;
}
void solve_problems()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		vec[i].clear();
		int u,v;
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	int minn=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=(1<<(n+1))-1;i++)
	{
		if(check(i))
		{
			minn=min(minn,1LL);
		}
	}
	cout<<minn<<"\n";
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,T=1;
	cin>>c>>T;
	for(int t=1;t<=T;t++)
	{
		solve_problems();
	}
	return 0;
}
