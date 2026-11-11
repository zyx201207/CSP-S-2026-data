#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[1000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t!=0)
	{
		t--;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			if(x[i-1]+d<=x[i])n=i-1;
		}
		d=d/abs(x[2]-x[1]);
		if(d<=1)cout<<0<<endl;
		else cout<<n-2*d+1<<endl;
	}
	return 0;	
} 

