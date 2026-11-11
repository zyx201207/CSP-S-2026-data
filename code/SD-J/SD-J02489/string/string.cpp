#include<bits/stdc++.h>
using namespace std;
struct A
{
	long long m;
	char c;
};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	A a[200010];
	int n;
	cin>>n;
	
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].m>>a[i].c;
	}
	long long d=0;
	int j=n;
	for(int i=1;i<=n;i++)
	{
		d=a[i].m;
		
		while(d)
		{
			if(d<a[j-i+1].m)
			{
				if(a[i].c!=a[j-i+1].c)
				{
					ans+=d;
						
				}
				a[j-i+1].m-=d;
				d=0;
				j+=1;
			}
			else if(d==a[j-i+1].m)
			{
				if(a[i].c!=a[j-i+1].c)
				{
					ans+=d;
						
				}
				d=0;
			}
			else
			{
				
				if(a[i].c!=a[j-i+1].c)
				{
					ans+=d;
				}
				d-=a[j-i+1].m;
				j-=1;
			}
		}
	}
	ans/=2;

	cout<<ans;

	fclose(stdin);
	fclose(stdout);
	return 0; 
}
