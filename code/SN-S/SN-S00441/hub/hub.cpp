// 门可铭 辅轮中学 SN-S00441
#include <bits/stdc++.h>
using namespace std;
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int u,v;
		cin>>u>>v;
	}
	cout<<((((n+1)/2)-k+3)/4)+1;
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T=1;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
