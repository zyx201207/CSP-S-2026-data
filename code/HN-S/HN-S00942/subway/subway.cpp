/*
此外，B 市的地铁网络是连通的，
即任意两个地铁站都可以通过若干条线路互相到达。
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mkp make_pair
const int Llmax=0x3f3f3f3f3f3f3f;

const int N=500,M=5e5,D=20,Q=1e5;
int w[M+105];
struct Stt
{
	int a,ti;
};
vector <Stt> stt[N+105];
int xx[Q+105],yy[Q+105];

vector <pair<int,int> > pict[M+N+105];
int dis[M+N+105];
priority_queue <pair<int,int> > xl;
bool vis[M+N+105];
void dijk (int n, int m, int st)
{
	for (int i=1; i<=m+n; i++)
	{
		dis[i]=Llmax; vis[i]=0;
	}
	dis[st]=0;
	xl.push(mkp(0,st));
	while (xl.size())
	{
		int now=xl.top().second; xl.pop();
		if (vis[now]) continue;
		vis[now]=1;
		for (int i=0; i<pict[now].size(); i++)
		{
			int next=pict[now][i].first,edis=pict[now][i].second;
			if (dis[now]+edis<dis[next])
			{
				dis[next]=dis[now]+edis;
				xl.push(mkp(-dis[next],next));
			}
		}
	}
	return;
}

signed main ()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for (int i=1; i<=m; i++)
	{
		scanf("%lld",&w[i]);
	}
	for (int i=1; i<=n; i++)
	{
		int k; scanf("%lld",&k);
		for (int j=0; j<k; j++)
		{
			Stt x;
			scanf("%lld %lld",&x.a,&x.ti);
			stt[i].push_back(x);
		}
	}
	for (int i=1; i<=q; i++)
	{
		scanf("%lld %lld",&xx[i],&yy[i]);
	}
	
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<stt[i].size(); j++)
		{
			pict[stt[i][j].a].push_back(mkp(m+i,stt[i][j].ti));
			pict[m+i].push_back(mkp(stt[i][j].a,stt[i][j].ti));
		}
	}
	for (int i=1; i<=q; i++)
	{
		dijk(n,m,xx[i]);
		printf("%lld\n",w[xx[i]]+dis[yy[i]]+w[yy[i]]);
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

32
17
*/

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16
*/
