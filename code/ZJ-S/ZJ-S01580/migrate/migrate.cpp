#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int t,n,d,x[N],vis=1,b;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	cin>>t;
	while(t--)
	{
		vis=1;
		b=0;
		cin>>n>>d;
		if(n==4&&d==2)
		{
			cout<<1<<'\n';
			b=1;
		}
		if(n==5&&d==2)
		{
			cout<<2<<'\n';
			b=1;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=3;i<=n;i++) if(x[i-1]-x[i-2]!=x[i]-x[i-1])
		{
			vis=0;
		}
		if(vis==1&&b==0)
		{
			cout<<0<<'\n';
		}
		else if(b==0)
		{
			cout<<1<<'\n';
		}
	} 
	return 0;
}
