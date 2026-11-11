#include <bits/stdc++.h>
using namespace std;
int n,k,fa[1000005],dp[1000005],d[1000005],xd[1000005],xdp[1000005],s[1000005];
vector<int> a[1000005],p;
stack<int> st;
inline bool check(int x)
{
	int ans=n;
	reverse(p.begin(),p.end());
	for(auto u:p)
	{
		dp[u]=1;
		for(auto v:a[u]) if(v!=fa[u]) dp[u]+=dp[v]*(d[v]>x);
	}
	reverse(p.begin(),p.end());
	xdp[1]=0;
	for(auto u:p)
	{
		int t=1+xdp[u]*(xd[u]>x);
		for(auto v:a[u]) if(v!=fa[u])
		{
			t+=dp[v]*(d[v]+1>x);
		}
		for(auto v:a[u]) if(v!=fa[u]) xdp[v]=t-(dp[v]*(d[v]+1>x));
	}
	ans=min(ans,dp[1]);
//	for(int i=1;i<=n;i++) cout << d[i] << ' ' << dp[i] << ' ' << xdp[i] << ' ' << xdp[fa[i]]+min(dp[i],max(1,s[i]-2*x)) << '\n';
	for(int i=2;i<=n;i++)
	{
		ans=min(ans,xdp[i]-1+min(dp[i],max(1,s[i]-2*x)));
	}
//	cout << x << ' ' << ans << "\n\n";
	return ans<=k;
}
inline void myst()
{
	cin >> n >> k;
	p.clear();
	for(int i=1;i<=n;i++) a[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	fa[1]=-1;
	while(!st.empty()) st.pop();
	st.push(1);
	while(!st.empty())
	{
		int u=st.top();
		p.push_back(u);
		st.pop();
		for(auto v:a[u]) if(v!=fa[u])
		{
			fa[v]=u;
			st.push(v);
		} 
	}
	reverse(p.begin(),p.end());
	for(auto u:p)
	{
		d[u]=1;
		s[u]=1;
		for(auto v:a[u]) if(v!=fa[u]) d[u]=max(d[u],d[v]+1),s[u]+=s[v];
	}
	xd[1]=-1;
	reverse(p.begin(),p.end());
	for(auto u:p)
	{
		int id=0,mx=xd[u]+1,secmx=xd[u]+1;
		for(auto v:a[u]) if(v!=fa[u])
		{
			if(d[u]+2>mx)
			{
				secmx=mx;
				mx=d[u]+2;
				id=u;
			}
			else secmx=max(secmx,d[u]+2);
		}
		for(auto v:a[u]) if(v!=fa[u])
		{
			if(v==id) xd[v]=secmx;
			else xd[v]=mx;
		}
	}
	int l=0,r=n-2,ans=n-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout << ans << '\n';
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--) myst();
}
