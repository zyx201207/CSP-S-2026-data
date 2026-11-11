#include<iostream>
using namespace std;
long long int a[200005];
int main()
{
	freopen("and .in","r",stdin);
	freopen("and .out","w",stdout);
	int n,m,i,j,k,q,w,e,r,t,maxx=-1,s=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		cout<<"0";
	}
	else if(m==2)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i!=j)
				{
					s=a[i]&a[j];
					if(s>maxx)
					{
						maxx=s;
					}
					s=0;
				}
			}
		}
	}
	else if(m==3)
	{
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(i!=j&&j!=k)
					{
						s=a[i]&a[j]&a[k];
						if(s>maxx)
						{
							maxx=s;
						}
						s=0;
					}
				}
			}
		}
	}
	cout<<maxx;
	return 0;
}