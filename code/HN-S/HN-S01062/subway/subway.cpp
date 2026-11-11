/*
14:07 hi.@[tzhengqing](/user/1058570) here.

well well, so many things happened these days.
(such as got banned in florr.io?)

CSP 2023 5+85
CSP 2024 320+180
NOIP 2024 204
CSP 2025 214
NOIP 2025 124

what will go on next?

to be honest there's no reason to learn OI anymore, but I still go on.

that's the charm.

all in all,welcome to join qaswed12 OI Round 2.(oh no i forgot the link, maybe 361669? seems to be not lol)

coffee tastes good.

(try to find the wrong usage of the grammar! quite funny)

I guess emojis are ok. but there is 1% chance I got 0pts, that's bad.

maybe I shouldn't be here, cuz I forgot most of the lyrics. oh no.

---

I used 11min to print the text upside. Coding time now.

CSP-S 2026 AK +++!

---

14:39 T2 code here.

我讨厌图论，怎么每年都考。看看有没有 tarjan 成分，有我就直接不做了。

谁看的懂题。。？

何数据范围。

What is this?!

老牧师铃声。

这个 w 是干啥的？？？

写一下性质吧。w 除了首尾加上之外不用管，对链上的每两点之间连边 (i,j,t[i]+t[j]).

76 是送的，哎不对 76 凭啥是送的，我好像不会 B。烧烤中。

边权全部相等有啥用。

边权全部相等，时光倒流~（？）

连通块之间连边 min(t[x][i],t[y][j])，这个双指针即可 O(n)，floyd 跑出来，答案即为 min(w[x]+w[y]+t[p][x]+t[q][j]+dis[p][q])，时间复杂度 O(n^3+(m+q)d^2).

注意卡常。

15:41 一遍过，爽了。

1h 过 2 题，优势在我！！！

（虽然只有青）
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005,p=998244353,inf=100000000010299ll;
int c,n,m,d,q,dis[505][505],w[N];
vector<pair<int,int> >e[N];
void sol()
	{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
		{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
			{
			int a,t;cin>>a>>t;
			e[a].push_back(make_pair(i,t));
			}
		}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)
		{
		for(int j=0;j<e[i].size();j++)
			{
			pair<int,int> x=e[i][j];
			for(int k=j+1;k<e[i].size();k++)
				{
				pair<int,int> y=e[i][k];
				dis[x.first][y.first]=min(dis[x.first][y.first],x.second+y.second);
				}
			}
		}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[j][i]);
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
		{
		int x,y,ans=inf;cin>>x>>y;
		for(int i=0;i<e[x].size();i++)for(int j=0;j<e[y].size();j++)
			{
			ans=min(ans,e[x][i].second+e[y][j].second+dis[e[x][i].first][e[y][j].first]);
			}
		cout<<ans+w[x]+w[y]<<'\n';
		}
	return;
	}
signed main()
	{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int t=1;while(t--)sol();
	return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//Need space here.
