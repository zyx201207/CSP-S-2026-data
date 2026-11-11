#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=2e5+5;
int n,m,mx,a[N];
bool vis[N];
int F(int x)
{
	string S="";
	while(x)
	{
		S+=(x%2)+'0';
		x/=2;
	}
	return S.size();
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	IOS;cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		vis[i]=true;
		mx=max(mx,a[i]);
	}
	int L=F(mx);
	int ans=0;
	for(int i=L;i>=0;i--)
	{
		int cnt=0,k=1<<i;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==-1) continue;
			if(a[i]&k) ++cnt;
			else vis[i]=false;
		}
		if(cnt<m)
		{
			for(int i=1;i<=n;i++) vis[i]=true;
		}
		else
		{
			ans+=k;
			for(int i=1;i<=n;i++) if(!vis[i]) a[i]=-1;
		}
	}
	cout<<ans;
	return 0;
}