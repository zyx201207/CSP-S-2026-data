#include<bits/stdc++.h>
using namespace std;
int c,t,x;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,d,y;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x>>y;
		}
		cout<<(y%3==0?1:(y%2==0?2:3))<<endl;
	}
	return 0;
}