#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
int a[N];
int dis[N];
struct node{
	int v,w;
	bool operator<(const node &x)const{
		return w>x.w;
	}
};
vector<node> g[N];
void solve()
{
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]>d)
		{
			cout<<0<<'\n';
			return;
		}
	}
	int l=1;
	for(int r=1;r<=n;r++)
	{
		if(a[r]-a[l]==d+1)
		{
			ans++;
		}
		if(a[r]-a[l]>=d+1)
		{
			l++;
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		solve();
	}
	return 0;
}
