#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int x=a[2]-a[1];
		int y=d/x;
		if(y*2<=n) cout<<n-y*2+1;
		else cout<<0<<'\n'; 
	}
	return 0;
}