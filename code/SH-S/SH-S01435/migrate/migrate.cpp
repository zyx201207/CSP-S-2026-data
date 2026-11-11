#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[200005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		int n,d;
		memset(x,0,sizeof(x));
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
		}
		if(c>=11&&c<=12)
		{
			if(x[1]-x[0]>=2*d)cout<<0<<endl;
		}
	}
	return 0;
}
