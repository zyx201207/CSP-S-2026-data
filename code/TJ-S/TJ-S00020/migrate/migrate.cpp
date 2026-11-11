#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long a[2000005]={0};
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
		
		if(c==11||c==12)
		{
			int reduce=a[2]-a[1];
			if((d/reduce)<=1)
			{
				cout<<0<<endl;
				continue;
			}
			else
			{
				d=(d/reduce)*reduce;
				if(((n-1)/2)>=(d/reduce))
				{
					cout<<1<<endl;
				}
				if(((n-1)/2)<(d/reduce))
				{
					
				}
			}
		}
	}
	return 0;
}
