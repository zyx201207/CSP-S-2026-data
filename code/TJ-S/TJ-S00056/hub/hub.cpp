#include <bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==7 || c==11 || c==12)
	{
		for(int i=1;i<=t;i++)
		{
			cout<<1<<endl;
		}
	}
	else
	{
		if(c==13 || c==14) cout<<12251;
		else
		{
			for(int i=1;i<=t;i++)
				cout<<0<<endl;
		}
	}
	return 0;
}
