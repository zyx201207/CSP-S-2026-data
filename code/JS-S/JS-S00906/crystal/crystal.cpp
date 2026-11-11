#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long d[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n;
	long long m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	for(long long i=1;i<n;i++)
		d[i]=a[i+1]-a[i];
	bool dc=true;
	for(long long i=1;i<n-1;i++)
	{
		if(d[i]!=d[i+1])
		{
			dc=false;
			break;
		}
	}
	
	if(dc)
	{
		long long cha=d[1];
		long long sum=0;
		long long plus=1;
		long long cnt=0;
		while(sum<m)
		{
			sum+=plus*cha;
			plus++;
			cnt++;
		}
		cout<<cnt;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
