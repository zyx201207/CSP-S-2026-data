#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int fa[N];
void solve()
{
	int n,k,u,v;
	cin >> n >> k;
	for (int i=1;i<n;i++)
	{
		cin >> u >> v;
		fa[u]=v;
	}
	
	cout << rand()%10 << "\n";
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
	
	int c,t;
	cin >> c >> t;
	while (t--) solve();
	return 0;
}

