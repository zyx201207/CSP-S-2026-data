#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10;

int c,T;
int n,d;
int a[N];
int mmm;
int ans;

void dfs(int root,int u,int deep)
{
	if(deep==2)
	{
		ans++;
		return;
	}
	for(int i=u+1;i<=n;i++)
	{
		int dd=a[i]-a[u];
		if(dd>d)return;
		if(deep==0)dfs(root,i,deep+1);
		else 
		{
			if(a[i]>a[root]+d)dfs(root,i,deep+1);
		}
	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		mmm=2e18+10;
		memset(a,0,sizeof a);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=2;i<=n;i++)
		{
			mmm=min(mmm,a[i]-a[i-1]);
		}
		if(d<mmm)
		{
			cout<<0<<"\n";
			break;
		}
		for(int i=1;i<=n;i++)
		{
			dfs(i,i,0);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
