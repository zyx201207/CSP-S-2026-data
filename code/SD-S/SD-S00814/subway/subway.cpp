//I love Á÷Ó© forever
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int N=5e5+5;
struct node
{
	int u,v;
	long long w;
};
struct Node
{
	int x;
	long long w;
}a[N];
struct NODE
{
	int l,r,id;
}qu[N];
int ID,n,m,d,q,pos;
long long w[N],ans[N];
vector<node> nums[N];
long long dis[N];
bool check[N];
bool cmp(NODE a,NODE b)
{
	return a.l<b.l;
}
void bfs(int qi)
{
	for(int i=1;i<=m;i++)
	{
		check[i]=0;
		dis[i]=1000000000000000000;
	}
	dis[qi]=0;
	priority_queue<pair<long long ,int >,vector<pair<long long,int> >,greater<pair<long long ,int > > > qq;
	qq.push({0,qi});
	while(!qq.empty())
	{
		long long w=qq.top().first;
		int now=qq.top().second;
		qq.pop();
		if(check[now])
		{
			continue;
		}
		check[now]=1;
		for(auto nxt:nums[now])
		{
			if(dis[nxt.v]>dis[now]+nxt.w)
			{
				dis[nxt.v]=dis[now]+nxt.w;
				qq.push({dis[nxt.v],nxt.v});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>ID>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j].x>>a[j].w;
			for(int p=1;p<j;p++)
			{
				nums[a[j].x].push_back({a[j].x,a[p].x,a[j].w+a[p].w});
				nums[a[p].x].push_back({a[p].x,a[j].x,a[j].w+a[p].w});
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>qu[i].l>>qu[i].r;
		qu[i].id=i;
	}
	sort(qu+1,qu+q+1,cmp);
	int now=1;
	while(now<=q)
	{
		bfs(qu[now].l);
		int qi=qu[now].l;
		while(qu[now].l==qi)
		{
			ans[qu[now].id]=dis[qu[now].r]+w[qu[now].l]+w[qu[now].r];
			now++;
		}
		/*
		for(int i=1;i<=m;i++)
		{
			cout<<dis[i]<<" ";
		}
		cout<<endl;
		*/
	}
	for(int i=1;i<=q;i++)
	{
		cout<<ans[i]<<'\n';
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

