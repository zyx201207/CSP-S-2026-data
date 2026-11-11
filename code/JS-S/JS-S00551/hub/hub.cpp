#include <bits/stdc++.h>
using namespace std;
long long c,T,n,k,u,v;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for (int i=1;i<n;i++)
			cin>>u>>v;
		if (k==n)
			cout<<0<<endl;
		else if (k>=n/2)
			cout<<1<<endl;
		else
			cout<<n/2-k+1<<endl;
	}
	return 0;
}
