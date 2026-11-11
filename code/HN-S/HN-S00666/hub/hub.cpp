#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int c,t;
int n,k;
int fa[N];
struct node
{
	int u,v,w;
}g[N];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
void un(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y)
		fa[x]=y;
}
void kruskal()
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(g+1,g+n,cmp);
	int ans=0,cnt=0;
	for(int i=1;i<n;i++)
	{
		int u=g[i].u,v=g[i].v,w=g[i].w;
//		cout<<u<<" "<<v<<" "<<w<<"\n";
		if(find(v)!=find(u))
		{
			un(u,v);
			ans=max(ans,w);
			cnt++;
		}
		if(cnt==n-1)
			break;
	}
	cout<<ans<<"\n";
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n-1;i++)
	{
		cin>>g[i].u>>g[i].v;
		g[i].w=1;
	}
	kruskal();
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/

