#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const int N=5e5+10;
ll n,m,a[N],ans,s,cha;
vector<ll> g;
bool check2()
{
	for(int i=3;i<=min(n,(ll)10);i++)
	{
		if(a[i]-a[i-1]!=1) return false;
	}
	return true;
}
bool check3()
{
	ll cha=a[2]-a[1];
	for(int i=3;i<=min(n,(ll)10);i++)
	{
		if(a[i]-a[i-1]!=cha) return false;
	}
	return true;	
}
void dfs(ll len)
{
	if(len==n+1)
	{
		s=0;
		for(int i=1;i<g.size();i++)
		{
			
			s+=(g[i]-g[i-1])*i;
		}
		if(s<=m) ans=max(ans,g.size());
		return;
	}
	g.push_back(a[len]);
	dfs(len+1);
	g.pop_back();
	dfs(len+1);
}
void solve()
{
	sort(a+1,a+1+n);
	s=0;
	for(int i=2;i<=n;i++)
	{
		if(s+(a[i]-a[i-1])*(i-1)>=m)
		{
			cout<<i-1;
			return ;
		}
		s+=(a[i]-a[i-1])*(i-1);
	}	
}
void solve1()
{
	sort(a+1,a+1+n);
	dfs(1);
	cout<<ans;
}
void solve2()
{
	for(int i=1;i<=n;i++)
	{
		if(i*(i-1)/2>m) 
		{
			cout<<i-1;
			return;
		}
	}
}
void solve3()
{
	cha=a[2]-a[1];
	for(int i=1;i<=n;i++)
	{
		if((cha+a[i]-a[1])*(a[i]-a[1])/cha/2>m) 
		{
			cout<<i-1;
			return;
		}
	}	
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	ans=1;
	if(n<=16) solve1();
	else if(check2()) solve2();
	else if(check3()) solve3();
	else solve();
	return 0;
}
