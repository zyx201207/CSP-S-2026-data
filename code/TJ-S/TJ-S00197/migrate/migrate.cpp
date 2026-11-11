#include<bits/stdc++.h>
using namespace std;
int x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		int cha=x[2]-x[1];
		bool flagA=1;
		for(int i=2;i<=n;i++)
		{
			if(x[i]-x[i-1]!=cha)
			{
				flagA=0;
				break;
			}
		}
		if(flagA)
		{
			if(d<cha*2) 
				cout<<0<<endl;
			else
			{
				cout<<n<<endl;
			}
		}
	}
	return 0;
}
