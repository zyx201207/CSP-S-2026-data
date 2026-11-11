#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		sum+=x;
	}
	cout<<abs(sum);
	return ;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int T;cin>>T;while(T--) solve();
}