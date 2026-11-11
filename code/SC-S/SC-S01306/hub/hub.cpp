#include<bits/stdc++.h>
using namespace std;

int n,bh,t,k;

int  main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>bh>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1,x,y;i<n;i++)cin>>x>>y;
		cout<<(k+1)/2<<'\n';
	}
	return 0;
}