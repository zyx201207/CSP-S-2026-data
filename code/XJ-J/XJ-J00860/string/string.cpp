#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long k;
	string s;
}a[2000005];
long long n,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].k>>a[i].s;
	for(int i=1,j=n;i<j;i++)
	{
		if(a[i].s!=a[j].s&&i<j)
		{
			if(a[i].k>=a[j].k&&a[j].k>0&&i<j)
			{
				if(a[i].s!=a[j].s&&i<j)
					ans+=a[j].k;
				long long k=a[i].k-a[j].k;
				j--;
				while(k>0&&i<j)
				{
					if(a[j].k<=k&&i<j)
					{
						if(a[i].s!=a[j].s&&i<j)
							ans+=a[j].k;
						k-=a[j].k;
						j--;
					}
					else
					{
						if(a[i].s!=a[j].s&&i<j)
							ans+=k;
						a[j].k-=k;
						k=0;
					}
				}
			}
			else
			{
				if(a[i].s!=a[j].s&&i<j)
					ans+=a[i].k;
				a[j].k-=a[i].k;
			}
		}
		else
		{
			if(a[i].k>=a[j].k&&a[j].k>0&&i<j)
			{
				long long k=a[i].k-a[j].k;
				j--;
				while(k>0&&i<j)
				{
					if(a[j].k<=k&&i<j)
					{
						if(a[i].s!=a[j].s&&i<j)
							ans+=a[j].k;
						k-=a[j].k;
						j--;
					}
					else
					{
						if(a[i].s!=a[j].s&&i<j)
							ans+=k;
						a[j].k-=k;
						k=0;
					}
				}
			}
			else
			{
				if(a[i].s!=a[j].s&&i<j)
					ans+=a[i].k;
				a[j].k-=a[i].k;
			}
		}
	}
	cout<<ans;
	return 0;
}
