#include <bits/stdc++.h>
using namespace std;
int main()
{
	int c,t,ans=0,a[500005];
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int n,d,ans,g;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		g=a[2]-a[1];
		if(g<=d)	cout<<2<<endl;
		else cout<<0<<endl;
	}
	
	return 0;
}
