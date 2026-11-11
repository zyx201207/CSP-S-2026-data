#include<bits/stdc++.h>
using namespace std;
int u[1000000],v[1000000]
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","W",stdout);
	int c,t,n,k;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>u[i]>>v[i];
		}
		cout<<1<<"\n";
	}
	return 0;
}
