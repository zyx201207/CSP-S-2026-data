#include<bits/stdc++.h>
using namespace std;
long long a[600005],ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long i,j,k,flag=1;
	long long n,m; 
	cin >> n >> m;
	if(n==1)
	{
		cout << 1;
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	long long x;
	x=a[2]-a[1];
	for(i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=x) flag=0;
	}
	if(flag==1)
	{
		i=1;
		while(m>=0)
		{
			m-=x*i;
			i++;
		}
		cout << i-1;
	}
	else
	{
		for(i=n;i>=1;i--)
		{
			j=i;
			long long t=m,cnt=0;
			while(j>=0)
			{
				t=t-a[i]+a[j];
				if(t>=0) cnt++;
				else break;
				j--;
			}
			ans=max(ans,cnt);
		}
		cout << ans;
	} 
	return 0;
}
