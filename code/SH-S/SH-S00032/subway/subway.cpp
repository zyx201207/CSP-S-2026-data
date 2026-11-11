#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q; //测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
long long k[501];    //第i条线路经过的地铁站数
long long f1[500001];      //从每个地铁站的地铁口走到站厅需要的时间
long long f2[501][50001]; //从该地铁站的站厅走到第i条线路的站台需要的时间
bool ff1[500001];    //第a个地铁站是否已走过
bool ff2[501];       //第i个地铁线是否已坐过 
long long ans[100001];
void g1(long long i,long long b,long long cnt,long long q);
void g2(long long a,long long b,long long cnt,long long q);
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1; i<=q; i++)
		ans[i]=-1;
	for(long long i=1; i<=m; i++)
		cin>>f1[i];
	for(long long i=1; i<=n; i++)
	{
		cin>>k[i];
		for(long long j=1; j<=k[i]; j++)
		{
			long long a;
			cin>>a;
			cin>>f2[i][a];
		}
	}
	for(long long i=1; i<=q; i++)
	{
		long long a,b;
		cin>>a>>b;
		g2(a,b,f1[a]+f1[b],i);
	}
	for(long long i=1; i<=q; i++)
		cout<<ans[i]<<"\n";
	return 0;
}
void g1(long long i,long long b,long long cnt,long long q) //地铁下地铁站
{
	ff2[i]=1;
	for(long long a=1; a<=m; a++) //枚举地铁站
	{
		if(f2[i][a]!=0 && ff1[a]==0)
			g2(a,b,cnt+f2[i][a],q);
	}
	ff2[i]=0;
}
void g2(long long a,long long b,long long cnt,long long q) //地铁站上地铁
{
	if(a==b)
	{
		if(ans[q]==-1 || cnt<ans[q])
			ans[q]=cnt;
		return;
	}
	ff1[a]=1;
	for(long long i=1; i<=n; i++) //枚举地铁线 
	{
		if(f2[i][a]!=0 && ff2[i]==0)
			g1(i,b,cnt+f2[i][a],q); 
	}
	ff1[a]=0;
}
