#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,mi,d,q,x,dsj[500005],y,w[500005],ljd[505][21]/*第i条线路连接的站点*/,yxs[500005]/*第i个点有几条线路*/,tim,zd,k[505]/*第i条线路连接几个站点*/,yxl[500005][21]/*第i个站点有的线路*/,t[500005][21]/*第i个站点走到第j条线路的耗时*/;
bool ff[500005];
void dfs(int dd/*点前点位*/,int mb/*将到点位*/,int ss/*目前花费总时间*/,int sx/*上一次乘车线路*/)
{
//	cout<<dd<<' '<<ss<<'\n';
	if(ss<=dsj[dd]) dsj[dd]=ss;
	else return;
	if(dd==mb)
	{
		mi=min(mi,ss+w[mb]+t[mb][sx]);
		return;
	}
	for(int i=1;i<=yxs[dd];i++)//枚举线路
	{
		int xl=yxl[dd][i];
		for(int j=1;j<=k[xl];j++)
		{
			if(ff[ljd[xl][j]]==0)//去到那个点
			{
				if(xl!=sx&&sx!=0)
				{	
					ff[dd]=1;
					dfs(ljd[xl][j],mb,ss+t[dd][sx]+t[dd][xl],xl);
					ff[dd]=0;
				}
				else
				{
					ff[dd]=1;
					dfs(ljd[xl][j],mb,ss+t[dd][xl],xl);
					ff[dd]=0;
				}
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>zd>>tim;
			yxl[zd][++yxs[zd]]=i;
			ljd[i][j]=zd;
			t[zd][i]=tim;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		mi=2e9;
		memset(dsj,0x3f,sizeof(dsj));
		memset(ff,0,sizeof(ff));
		dfs(x,y,w[x],0);
		cout<<mi<<'\n';
	}
	return 0;
}