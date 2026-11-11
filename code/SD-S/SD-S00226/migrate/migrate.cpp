#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<queue>
#define int long long
using namespace std;
const int N=2e6+50,inf=9e18;
int a[N],f[N],g[N],s[N];
inline void solve()
{
	int n,d,ans=0;
	cin>>n>>d;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=0;
	}
	if(n>5000&&flag)
	{
		int t=a[2]-a[1];
		int cc=d/t+2;
		if(cc<=4||n-cc<=4) cout<<0<<'\n';
		else cout<<max(n-cc+1,0ll)<<'\n';
		return;
	}
	for(int x=1;x<=n;x++)
	{
		deque<int>q;
		for(int i=1;i<=n;i++) f[i]=inf,g[i]=s[i]=0;
		f[x]=0,g[x]=1,s[0]=1;
		q.push_front(x);
		for(int i=x+1;i<=n;i++)
		{
			while(!q.empty()&&a[i]-a[q.front()]>d)
				s[f[q.front()]]-=g[q.front()],q.pop_front();
			if(q.empty()) break;
			f[i]=f[q.front()]+1;
			if(s[f[q.front()]]==2) ans++;
			g[i]=s[f[q.front()]];
			s[f[i]]+=s[f[q.front()]];
			while(!q.empty()&&f[i]<f[q.back()])
				s[f[q.back()]]-=g[q.back()],q.pop_back();
			q.push_back(i);
//			cout<<"i:"<<i<<' '<<f[i]<<' '<<s[f[i]]<<' '<<g[i]<<'\n';
//			cout<<"q:"<<q.front()<<' '<<f[q.front()]<<' '<<s[f[q.front()]]<<'\n';
		}
//		cout<<x<<' '<<ans<<'\n';
	}
	cout<<ans<<'\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/
