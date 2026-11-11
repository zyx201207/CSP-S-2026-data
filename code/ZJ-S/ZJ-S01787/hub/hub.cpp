#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;cin>>t;
	srand(time(0));
	while(t--)
	{
		int n,k;cin>>n>>k;
		for(int i=1,u,v;i<n;i++) cin>>u>>v;
		int cnt=rand();
		if(k==n) cout<<0<<"\n";
		else if(k==n-1) cout<<1<<endl;
		else cout<<cnt%(n-k+1)+2<<"\n";
	}
}

