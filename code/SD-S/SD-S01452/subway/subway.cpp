#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
int read()
{
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
const int N=510;
const int M=500010;
int c,n,m,d,q;
int w[M];
int k[N];
vector<pair<int,int> > ed[M+N];
priority_queue<pair<int,int> > lq;
int cnt;
ll dis1[N][N];
ll ldis[M];
vector<pair<int,int> > down[M];
void sol1()
{
	c=read();n=read();m=read();d=read();q=read();
	//n为线路数，m为站数 
	for(int i=1;i<=m;i++) w[i]=read();
	//cnt=m;
	//1-m表示站台 
	for(int i=1;i<=n;i++)
	{
		k[i]=read();
		//int u=read(),t=read();
		//ed[m+i].emplace_back(u,t);
		//ed[u].empalce_back(m+i,t);
		for(int j=1;j<=k[i];j++)
		{
			int u=read(),t=read();
			//++cnt;
			ed[u].emplace_back(m+i,t);
			ed[m+i].emplace_back(u,t);
			//ed[cnt-1].emplace_back(cnt,0);
			//ed[cnt].emplace_back(cnt-1,0);
			//down[v].emplace_back(i,t2);
			//u=v;
		}
	}
//	for(int i=1;i<=n+m;i++) {for(pair<int,int> j:ed[i]) cout<<j.fi<<" ";
//	cout<<'\n';
//	}
	//int now=m+1;
	memset(dis1,0x3f,sizeof(dis1));
	for(int i=1;i<=n;i++)
	{
		dis1[i][i]=0;
		lq.emplace(0,i+m);
		memset(ldis,0x3f,sizeof(ldis));
		while(!lq.empty())
		{
			pair<int,int> pt=lq.top();
			lq.pop();
			for(pair<int,int> j:ed[pt.se])
			{
				if(ldis[j.fi]>dis1[i][pt.se-m]+j.se)
				{
					ldis[j.fi]=dis1[i][pt.se-m]+j.se;
					for(pair<int,int > j2:ed[j.fi])
					{
						if(dis1[i][j2.fi-m]>ldis[j.fi]+j2.se)
						{
							dis1[i][j2.fi-m]=ldis[j.fi]+j2.se;
							lq.emplace(-dis1[i][j2.fi-m],j2.fi);
						}
					}
				}
			}
		}
		//now+=k[i];
//		for(int j=1;j<=n;j++) cout<<dis1[i][j]<<' ';
//		cout<<'\n';
//		for(int j=1;j<=m;j++) cout<<ldis[j]<<' ';
//		cout<<'\n'; 
	} 
	for(int i=1;i<=q;i++)
	{
		int u,v;
		u=read();v=read();
		ll ans=LONG_LONG_MAX;
		for(pair<int,int> j:ed[u])  
			for(pair<int,int> j2:ed[v])
				ans=min(ans,j.se+j2.se+dis1[j.fi-m][j2.fi-m]);//,cout<<j.se<<' '<<j2.se<<' '<<dis1[j.fi-m][j2.fi-m]<<'\n';
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	sol1();
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/

