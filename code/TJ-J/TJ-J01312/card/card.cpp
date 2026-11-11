#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],b[500005],c[500005],p;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i-p;j<=n;j++)
		{
			c[i-p]+=b[i];
			for(int x=i-p;x<j;x++)
			{
				if(c[x]%1000000==c[j]%1000000)
				{
				for(int y=x;y<=j;x++)
				{
					c[y]=0;
				}
				p+=j-x;
		    	}
			}
		}
		for(int j=1;j<=i-p;j++)
		{
			a[j]++;
		}
		cout<<a[i]<<" ";
	}
	return 0;
}
