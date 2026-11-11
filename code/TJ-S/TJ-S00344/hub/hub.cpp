#include <bits/stdc++.h>
using namespace std;
#define int long long 
int u[20000005];
int v[20000005];
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	cin>>n,k;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i]>>v[i];
	}
	cout<<c<<endl;
	cout<<t;
	return 0;
}
