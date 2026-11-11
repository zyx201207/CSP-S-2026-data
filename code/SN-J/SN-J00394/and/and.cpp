#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long b[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,y;
	int sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int y=a[i]&a[j]; 
			if(y>sum)
			{
				sum=y;
			}
		}
	}
	cout<<sum;
	return 0;
}
