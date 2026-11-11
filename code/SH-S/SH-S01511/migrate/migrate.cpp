#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[10000005],k,ch[1000005],p[1000005],cnt;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c;
	if(c==0)
	c++;
	while(c--)
	{
		cin>>t;
		for(int i=1;i<=t;i++)
		{
			cnt=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			cin>>x[i];
			k=1-x[1];
			for(int i=1;i<=n;i++)
			x[i]+=k;
			for(int i=1;i<=n;i++)
				ch[i]=x[i+1]-x[i]; 
			for(int i=1;i+3<=n;i++)
			{
				if(x[i+3]-x[i]>d)
				{
						cnt++;
				}
			}
			for(int i=1;i+4<=n;i++)
			{
				if(x[i+4]-x[i]>d)
				{
					if(x[i+3]-x[i]<d)
					{
						if(x[i+2]-x[i]<d) 
						{
							if(x[i+4]-x[i+3]<d)
							{
								if(x[i+4]-x[i+2]<d)
								cnt++;
							}
						}
					}
				}
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}
