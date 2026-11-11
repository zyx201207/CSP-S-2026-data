//SN-S00175
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510;
const ll INF=1e18;
int n,m,c,d,q;//m个口，n条线 
int kou[N],a[N][N],t[N][N];
bool vis[N],flag=true;//i线
ll ans;
int e[N][N];//k==2
void dfs(int frm, int ed,      ll sum,        int nowi)///不会.. 
//      当前在，最终目的地，当前已用时间 ，当前所在线路 
{
	if(frm==ed)
	{
		ans=min(ans,sum);
		return;
	}
	if(sum>ans) return;
	for(int i=1;i<=n;i++)//i线路 
	{
		if(!a[i][frm] || vis[i])	continue;
		for(int j=1;j<=n;j++)
		{
			if(!a[i][j] || j==frm) continue;
			vis[i]=true;
			if(i!=nowi) dfs(j,ed,sum+t[i][frm]+t[i][j],i);
			else dfs(j,ed,sum,i);
			vis[i]=false;
		}
	}
}
queue<int> que;
ll dis[N];
bool inq[N];
void SPFA(int st,int ed)
{
	for(int i=1;i<=m;i++)
	{
		if(i==st) dis[i]=0;
		else dis[i]=INF;
	}
	que.push(st);
	inq[st]=true;
	while(!que.empty())
	{
		int u=que.front();
		inq[u]=false;
		que.pop();
		for(int i=1;i<=m;i++)
		{
			if(i==u || e[u][i]==0) continue;
			if(dis[i]>dis[u]+e[u][i])
			{
				dis[i]=dis[u]+e[u][i];
				if(!inq[i]) 
				{
					que.push(i);
					inq[i]=true;
				}
			}	
		}
	}
	cout<<dis[ed]+kou[st]+kou[ed]<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>kou[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		if(k>2) flag=false;
		if(flag && k==2)
		{
			int a1,a2,t1,t2;
			cin>>a1>>t1>>a2>>t2;
			e[a1][a2]=e[a2][a1]=t1+t2;
		}
		else
		{
			for(int j=1;j<=k;j++)
			{
				int zhan;
				cin>>zhan>>t[i][zhan];
				a[i][zhan]=1;
			}
		}
	}
	for(int r=1;r<=q;r++)
	{
		ans=INF;
		int st,ed;
		cin>>st>>ed;
		if(flag)
		{
			SPFA(st,ed);
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i][st]) dfs(st,ed,0,i);//baosou 
			}
			cout<<ans+kou[st]+kou[ed]<<'\n';
		}	
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
