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

17:12 哎哎我怎么不会 T3，滚过来看 T4 了。/ll

考虑设 dp[i][j][x][0/1/2] 表示 i 的子树内部用了 j 个点，与 i 距离为 x，0/1/2 个连通块的最小距离。

18:09 不是不是这个怎么暴力就有 20，我咋没看到。现在写吧。

18:20 怎么 10min 打了 1.3kb，感觉代码状态还是在的。  
可惜脑子不太清醒。哎，瞎打的。

应该不会挂分吧... 100+100+48+20=268，糖完了。

哎哎我怎么这么菜，感觉左边的学弟好像切了好多题，但是我的做题是滚木。。

至今没有切过蓝以上，可能 recollector 是我唯一的机会，可惜我没有珍惜。。

生活还要继续，小 T 衷心希望大家都能过上幸福的生活，我们 NOIP 再见。

> "But I still say, they are flowers."
> "If you like."
> "Did you sell them?"
> "I'm afraid not."
> "But, maybe we can make a deal."
> "What do you mean?"
>
> ---
>
> "You see, you don't need to leave them anywhere."
> "I'll buy them, but then, I'll leave them, for you."
>                                        ——《Flower Dance》
 
（希望我写的是对的）
 
welcome to join qaswed12 OI Round 2!!!!!
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1005,p=998244353,inf=100000000010299ll;
int c,n,k,a[N],fa[N],ans=inf;
vector<int>e[N];
int find(int x){return (x==fa[x]?fa[x]:fa[x]=find(fa[x]));}
map<int,int>mp;
int dfss(int x,int f)
	{
	if(a[x])return 0;
	int ans=inf;
	for(int i=0;i<e[x].size();i++)
		{
		int d=e[x][i];
		if(d==f)continue;
		ans=min(ans,dfss(d,x)+1);
		}
	return ans;
	}
void work()
	{
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)
		{
		if(!a[i])continue;
		for(int j=0;j<e[i].size();j++)
			{
			int d=e[i][j];
			if(find(d)==find(i)||!a[d])continue;
			fa[find(d)]=find(i);	
			}
		}
	mp.clear();
	for(int i=1;i<=n;i++)if(a[i]){mp[find(i)]++;if(mp.size()>2)return;}
	int anss=0;
	for(int i=1;i<=n;i++)anss=max(anss,dfss(i,i));
	ans=min(ans,anss);
	}
void dfs(int x,int now)
	{
	if(x==n+1)
		{
		if(now==k)work();
		return;	
		}
	if(now<k){a[x]=1;dfs(x+1,now+1);}
	a[x]=0;dfs(x+1,now);
	}
void sol()
	{
	cin>>n>>k;ans=inf;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++){int x,y;cin>>x>>y;e[x].push_back(y);e[y].push_back(x);}
	dfs(1,0);cout<<ans<<'\n';
	return;
	}
signed main()
	{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>c>>t;while(t--)sol();
	return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//Need space here.
