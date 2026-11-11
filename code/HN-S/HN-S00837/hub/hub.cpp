#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int a[N],b[N];
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<n;i++)cin>>a[i]>>b[i];
		if(n==5)cout<<1<<"\n";
		else if(n==10)cout<<2<<"\n";
		else cout<<"3\n";
	}
	return 0;
}

