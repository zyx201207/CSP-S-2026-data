#include<bits/stdc++.h>
#define ll long long
#define PI pair<ll,ll>
using namespace std;
inline ll read()
{
	ll re=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		re=(re<<3)+(re<<1)+c-'0';
		c=getchar();
	}
	return re*f;
}
inline void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
const int maxn=2e6;//////////////////////////////////////
ll n,m,d,_;
ll cnt;
struct node{
	ll v,w;
};
vector<node>a[maxn];
bool h[maxn];
ll dis[maxn];
priority_queue<PI,vector<PI>,greater<PI> >q;
void dij(ll root)
{
	while(!q.empty())q.pop();
	for(ll i=1;i<=cnt;i++)h[i]=0,dis[i]=1e18;
	dis[root]=0;
	q.push({0,root});
	while(!q.empty())
	{
		ll u=q.top().second;
		q.pop();
		if(h[u])continue;
		h[u]=1;
		for(ll i=0;i<a[u].size();i++)
		{
			ll v=a[u][i].v;
			ll w=a[u][i].w;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	//freopen("subway5.in","r",stdin);
	//freopen("tst.txt","w",stdout);
	
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll c=read();
	n=read();m=read();d=read();_=read();
	for(ll i=1;i<=m;i++)
	{
		ll w=read();
		a[i].push_back({i+m,w});
		a[i+m].push_back({i,w});
	}
	cnt=2*m;
	for(ll i=1;i<=n;i++)
	{
		ll len=read();
		ll last;
		for(ll j=1;j<=len;j++)
		{
			ll now=read();
			ll w=read();
			cnt++;
			a[now+m].push_back({cnt,w});
			a[cnt].push_back({now+m,w});
			if(j>=2)
			{
				a[cnt].push_back({last,0});
				a[last].push_back({cnt,0});
			}
			last=cnt;
		}
	}
	//for(int i=1;i<=cnt;i++){for(int j=0;j<a[i].size();j++)cout<<a[i][j].v<<' ';cout<<'\n';}
	while(_--)
	{
		ll u=read();ll v=read();
		dij(u);
		write(dis[v]);
		putchar('\n');
	}
	return 0;
}
/*



1~m subway kou

m+1~2m subway ting


2m~ ?   subway lu


dont press F11

seek if need long long

ensure function return

ensure file & extra output




0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2



*/
