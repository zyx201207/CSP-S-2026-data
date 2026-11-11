#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)cin>>u>>v;
		if(k%3==2)cout<<"1\n";
		if(k%3==1)cout<<"0\n";
		if(k%3==0)cout<<"2\n";
	}
	return 0;
}
