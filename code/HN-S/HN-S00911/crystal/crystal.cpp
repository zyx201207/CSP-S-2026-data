#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i+1]==a[i])
		{
			sum++;
		}
		else if(m>=(a[i+1]-a[i])*i)
		{
			m-=(a[i+1]-a[i])*i;
			sum++;
		}
		else
		{
			break;
		}
	}
	cout<<sum;
	return 0;
} 
