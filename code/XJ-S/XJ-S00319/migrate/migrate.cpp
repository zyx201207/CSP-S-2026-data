#include<bits/stdc++.h>
using namespace std;
int a[2000005];
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
			cin>>a[i];
		}
//		if(c==11 || c==12)
//		{
			int cha=a[2]-a[1];
			if(d<cha*2) 
			{
				cout<<"0"<<endl;
				continue;
			}
			else
			{
				cout<<d/2;
				continue;
			}
//		}
		
	}
	return 0;
}
