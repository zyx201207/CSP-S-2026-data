#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int sum=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(n%2==1 && m%2==1)
		{
			if(a[i]<=a[2])
			{
				sum+=1;
			}
		}
		else
		{
			if(a[i]<=a[n])
			{
				sum+=1;
			}
			
		}
	}
	cout<<sum;
	return 0;
}