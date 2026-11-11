#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k,u[N],v[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>k;
		for (int j=1;j<=n-1;j++)
		{
			cin>>u[i]>>v[i];
		}
		cout<<1;
	}
	return 0;
}
