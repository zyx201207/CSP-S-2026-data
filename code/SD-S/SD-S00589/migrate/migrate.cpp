#include <bits/stdc++.h>
using namespace std;
#define ll long long
int const N=2e6+5;
#define pii pair<ll,ll>
#define x first
#define y second
inline void read(ll &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		x=x*10+ch-'0',ch=getchar();
	x*=f;
}
ll C,T,n,d,a[N],t[N],ans,l[N],r[N];
ll dis[5005],cnt[5005];
queue<int> q;
void dij(int s)
{
	for(int i=1;i<=n;i++)
		dis[i]=1e18,cnt[i]=0;
	dis[s]=0,cnt[s]=1;q.push(s);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int v=r[u];v>u;v--)
		{
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push(v);
			}
			else if(dis[v]==dis[u]+1)
			{
				if(cnt[v]>2)
					break;
				cnt[v]+=cnt[u];
			}
		}
	}
}
void solve()
{
	read(n),read(d);//cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++)
		read(a[i]);//cin>>a[i];
	int hd=1,tl=1;
	for(int i=1;i<=n;i++)
	{
		while(a[i]-a[hd]>d)
			hd++;
		while(tl<n&&a[tl+1]-a[i]<=d)
			tl++;
		l[i]=hd,r[i]=tl;
	}
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			dij(i);
			for(int j=i+1;j<=n;j++)
				if(cnt[j]==2)
					ans++;
		}
		cout<<ans<<"\n";
		return;
	}
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<l[i]&&j<=n)
			t[r[j]]++,j++;
		ans+=t[l[i]+1];
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)
		t[i]=0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(C),read(T);//cin>>c>>t;
	while(T--)
		solve();
	return 0;
}
