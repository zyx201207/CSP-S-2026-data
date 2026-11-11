#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010],cha[2000010],i,j,k,c1,tot,c2;
int main()
{
	freopen("migrate.in","/r",stdin);
	freopen("migrate.out","/w",stdout);
	cin>>c>>t;
	for(int b=0;b<t;++b)
	{
		cin>>n>>d>>a[0];
		for(i=1;i<n;++i)
		{
			cin>>a[i];
			cha[i-1]=a[i]-a[i-1];
		}
		if(c==11 or c==12)
		{
			if(d%2!=0)
			{
				c1=1;
				--d;
			}
			if(a[1]-a[0]>d/2)
			{
				cout<<"0";
				continue;
			}
			else
			{
				if(c1==1)
				{
					++d;
				}
				for(i=2;i<=n;++i)
				{
					tot+=n-i;
				}
			}
		}
		else if(c==13 or c==14)
		{
			for(i=2;i<=n;++i)
			{
				tot+=n-i;
			}
		}
		else
		{
			for(i=0;i<n-2;++i)
			{
				for(j=i+3;j<n;++j)
				{
					for(k=i;k<j-1;++k)
					{
						if(cha[k]+cha[k+1]<=d)
						{
//							cout<<"("<<a[i]<<","<<a[j]<<")"<<endl;
							tot++;
							c2=1;
							break;
						}
					}
					if(c2==1)
					{
						break;
					}
				}
				c2=0;
			}
		}
		cout<<tot<<endl;
		tot=0;
	}
	return 0;
} 
