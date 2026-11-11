#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
		}
		if(n==k)
		cout<<0<<'\n';
		else 
		cout<<1<<'\n';
	}
	return 0; 
}
