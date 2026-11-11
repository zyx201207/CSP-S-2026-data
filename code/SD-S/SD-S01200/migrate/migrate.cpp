#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
int c,_;
int f1[N],g1[N];
int n,d;
int a[N];
int cnt[N];
int ans;
struct BIT
{
	int c[N];
	int lowbit(int x)
	{
		return x&(-x);
	}
	void clear()
	{
		for(int i=1;i<=n;i++)
		{
			c[i]=0;
		}
	}
	void add(int x,int v)
	{
		while(x<=n)
		{
			c[x]+=v;
			x+=lowbit(x);
		}
	}
	int query(int x)
	{
		int res=0;
		while(x)
		{
			res+=c[x];
			x-=lowbit(x);
		}
		return res;
	}
}F,G;
void solve1()
{
	cin>>n>>d;
	if(n==1)
	{
		cout<<0<<'\n';
		return;
	}
	ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		f1[i]=0;g1[i]=1;
		deque<int> dq;
		dq.push_back(i);
		for(int j=0;j<=n;j++) cnt[j]=(j==0);
		for(int j=i+1;j<=n;j++)
		{
			while(dq.size()&&a[dq.front()]<a[j]-d)
			{
				cnt[f1[dq.front()]]-=g1[dq.front()];
				dq.pop_front();
			}
//			cerr<<dq.front()<<' ';
			if(dq.size()) f1[j]=f1[dq.front()]+1,g1[j]=cnt[f1[dq.front()]];
			else break;
			cnt[f1[j]]+=g1[j];
			dq.push_back(j);
			if(g1[j]==2) ans++;
		}
//		for(int j=1;j<=n;j++)
//			cerr<<g1[j]<<' ';
//		cerr<<'\n';
	}
	cout<<ans<<'\n';
}
void solve2()
{
	cin>>n>>d;
	if(n==1)
	{
		cout<<0<<'\n';
		return;
	}
	ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	int x=a[2]-a[1];	
//	cerr<<n<<' '<<d<<' '<<x<<'\n';
	int k=d/x;
	int l=k+k-1;
	if(d<2*x||l>n-1) cout<<0<<'\n';
	else cout<<n-l<<'\n';
}
int f[N],g[N];
void solve3()
{
	cin>>n>>d;
	if(n==1)
	{
		cout<<0<<'\n';
		return;
	}
	ans=0;
	a[0]=-2e18;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=1;
 	F.clear();G.clear();
 	F.add(1,1);
 	F.add(2,-1);
	for(int i=1;i<=n;i++)
	{
		while(a[l]<=a[i]+d)
		{
			l++;
		}int q;
		if(l>3)
		{
			q=a[l-3];
		}
		else q=-2e18;
		
		int c=upper_bound(a+1,a+n+1,q+d)-a;
		int g=lower_bound(a+1,a+n+1,a[l-2]+d)-a;
		int h=lower_bound(a+1,a+n+1,a[l-1]+d)-a;
		if(c<=g)
		{
			G.add(F.query(i),c);
			G.add(-F.query(i),g);
			G.add(G.query(i),g);
			G.add(G.query(i),h-1);
			F.add(F.query(i),g);
			F.add(F.query(i),h-1);
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>_;
	if(c<=10)
	{
		while(_--) solve1();
	}
	if(c==0||c==11||c==12)
	{
		while(_--) solve2();
	}
	if(c==0||c==13||c==14)
	{
		while(_--) solve3();
	}
	return 0;
}
// 18:10 会有滚木用处 
