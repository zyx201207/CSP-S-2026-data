#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m ;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	if(m==1)
	{
		cout<<n;
	}
	else if(m==2)
	{
		int c=a[n];
		int e=a[n];
		int f;
		for(int i=1;i<=n;i++)
		{
			if(c<a[i])
			{
				c=a[i];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(e==a[i])
			{
				e++;
			}
		}
		f=n-e;
		if(a[n]==c)
		{
			cout<<f<<" "<<n;
		}
		else
		{
			cout<<n<<" "<<f;
		}
	}	
	return 0;
}
