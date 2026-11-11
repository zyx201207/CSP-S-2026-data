#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pll pair<long,long>
const int N=5000+10;
const int LINF=0x3F3F3F3F3F3F3F3F;
const int INF=0x3F3F3F3F;
inline int read()
{
	int ans=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
using namespace std;
int yl;
int n,d;
int a[N];
vector<pll> v[N];
int dis[N];
int c[N];
priority_queue<pll,vector<pll>,greater<pll>> q;
int ans=0;
void dij(int bg)
{
	q.push({0,bg});
	dis[bg]=0;
	while(!q.empty())
	{
		pll a=q.top();
		q.pop();
		for(auto x:v[a.second])
		{
			//cout<<x.first<<"*"<<x.second<<"**"; 
			if(dis[x.first]==dis[a.second]+x.second) c[x.first]++,q.push({dis[x.first],x.first});
			if(dis[x.first]>dis[a.second]+x.second)
			{
				dis[x.first]=dis[a.second]+x.second;
				q.push({dis[x.first],x.first});
				//cout<<a.second<<"--"<<x.first<<endl;
				c[x.first]=1;
			}
		}
	}
} 
void check()
{
	for(int i=1;i<=n;i++)
	{
		if(c[i]==2) ans++;
		dis[i]=INF;
		c[i]=0;
	}
}
void solve()
{
	ans=0;
	n=read(),d=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]<=d)
			{
				v[i].push_back({j,1});
				//cout<<i<<"*"<<j<<endl;
			}
			else break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		dij(i);
		check();
		//cout<<"&&&"<<ans<<endl;
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++) v[i].clear();
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1;
	yl=read();
	T=read();
	while(T--) solve();
	return 0;
}
