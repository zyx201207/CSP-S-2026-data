#include<bits/stdc++.h>
using namespace std;
const signed N=0;
int c,t,n,k;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1,a;i<n;i++)cin>>a;
		cout<<(n/k)-1<<"\n";
	}
	return 0;
}

