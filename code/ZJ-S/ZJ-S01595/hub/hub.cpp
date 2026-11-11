#include <bits/stdc++.h>
using namespace std;
const int N=4005;
int n,k;
vector<int>g[N];
void solve()
{
	cin>>n>>k;
	for (int i=2;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if (k==1)cout<<0<<endl;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
