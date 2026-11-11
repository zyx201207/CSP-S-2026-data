#include<bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		n-=1;
		int x,y;
		while(n--)
		{
			cin>>x>>y;
			cout<<x%3+y%5+c%4;
		} 
	}
	return 0;
}
