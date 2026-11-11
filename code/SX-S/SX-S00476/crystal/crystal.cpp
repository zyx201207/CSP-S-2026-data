#include<bits/stdc++.h>
#define maxn 500005
#define ll long long
using namespace std;
ll n,m,a[maxn],can[maxn],ans=INT_MIN,cnt;
bool vis[maxn];
void dfs(ll k,ll sum,ll y)
{
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		if(y<a[i]||sum+abs(a[i]-y)>m) return;
		vis[i]=1;
		//can[++cnt]=a[i];
		sum+=a[i]-y;
		ans=max(ans,k);
		dfs(k+1,sum,y);
		//cnt--;
		sum-=a[i]-y;
		vis[i]=0;
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
	//sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		dfs(1,0,a[i]);
	}
	cout<<ans;
	return 0;
}