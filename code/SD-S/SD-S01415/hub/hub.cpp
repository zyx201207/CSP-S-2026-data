#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
const int inf=1e9;
vector<int>v[N];
int b[N],n,k,mx,ans;
bool f[N],ff[N];
set<int>s[N];
void query(int x,int fu,int d)
{
	if(d)s[x].insert(d);
	for(auto i:v[x])
	{
		if(i!=fu)
		{
			query(i,x,d+1);
		}
	}
}
int get(int x)
{
	ff[x]=1;
	for(auto i:v[x])if(f[i] and !ff[i])get(i);
}
bool check()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i] and !ff[i])
		{
			get(i);
			cnt++;
		}
	}
	for(int i=1;i<=n;i++)ff[i]=0;
	return cnt<=2;
}
void dfs(int x)
{
	if(x==k+1)
	{
		if(check())
		{
			for(int i=1;i<=n;i++)s[i].clear();
			for(int i=1;i<=n;i++)
			{
				if(f[i])
				{
					query(i,0,0);
				}
			}
			mx=0;
			for(int i=1;i<=n;i++)
			{
				mx=max(mx,*s[i].begin());
				if(f[1] and f[4] and mx==3)cout<<i;
			}
			if(f[1] and f[4])cout<<mx;
			ans=min(ans,mx);
		}
		return;
	}
	for(int i=b[x-1];i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=1;
			b[x]=i;
			dfs(x+1);
			f[i]=0;
		}
	}
}
void solve()
{
	ans=inf;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)v[i].clear();
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	printf("%d\n",ans);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	b[0]=1;
	int id,t;
	cin>>id>>t;
	while(t--)solve();
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
