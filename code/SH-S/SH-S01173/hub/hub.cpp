#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int h,k;
		cin>>h>>k;
		long long ans=0;
		for(int i=2;i<=h;i++)
		{
			int x,y;
			cin>>x>>y;
			ans+=x;
		}
		cout<<ans/h<<endl;
	}
	
	return 0;
}
