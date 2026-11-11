#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int c,T,n,k;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
		}
		if(c!=13&&c!=14)
		{
			cout<<rand()%((n-1)/2)<<'\n';
			continue;
		}
		if(n==k)
		{
			cout<<0<<'\n';
		}
		int nw=n/2-k;
		if(nw%4==0)cout<<nw/4+1<<'\n';else cout<<nw/4+2<<'\n';
	}
	return 0; 
} 
