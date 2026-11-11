#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
long long n,m;
long long a[500005];
vector<long long> s[500005];
int main()
{
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>5000)
	{
		if(m<=5000000000000000)
		{
			long long x=a[2]-a[1],i=1;
			while(m-i>=0)
			{
				m-=i;
				i++;
			}
			cout<<i;
		}
		else
		{
			cout<<(long long)((sqrt(4*m+1)-1)/2);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			s[i].push_back(a[i]-a[j]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		long long sum=0;
		int cnt=1;
		for(int j=int(s[i].size())-1;j>=0;j--)
		{
			sum+=s[i][j];
			cnt++;
			if(sum>m)
			{
				cnt--;
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}