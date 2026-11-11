#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1ll<<32;
ll a[200010];
ll n,m;
ll hi = 32;
ll dfs(int x,int y){
	if (y<0) return 0;
	if (x>n)
	{
		if (y==0) return INF-1;
		return 0;
	}
	return max(dfs(x+1,y),(dfs(x+1,y-1)&a[x]));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	ll ma = 0;
	for (int i=1;i<=n;i++)
	{
		ma = max(ma,a[i]);
	}
	if (m==1)
	{
		cout<<ma;
		return 0;
	}
	if (m==2)
	{
		ma = 0;
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				ma = max((a[i]&a[j]),ma);
			}
		}
		cout<<ma;
		return 0;
	}
	if (m==n)
	{
		ma = INF;
		for (int i=1;i<=n;i++)
		{
			ma = (ma&a[i]);
		}
		cout<<ma;
		return 0;
	}
	if (n<=20)
	{
		cout<<dfs(1,m);
		return 0;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) cout<<a[i]<<' ';
	ll ans = INF-1;
	for (int i=n;i>=n-m+1;i--) ans = (ans&a[i]);
	cout<<ans;
	return 0;
} 
