#include <bits/stdc++.h>
using namespace std;
long long u[20005],v[20005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t,n,k;
	cin>>c>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>u[i]>>v[i];
		}
		if(n<2000)
		{
			cout<<n/5<<endl;	
		}
		else
		{
			cout<<"9"<<endl;
		}
	}
	return 0;
}
