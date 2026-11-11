#include<bits/stdc++.h>
using namespace std;
long long a[500005],ans;
struct cha{
	long long ch;
	long long big,small;
}c[600006];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<n;i++)
	{
		c[i].ch=a[i+1]-a[i];
	}
	for(long long i=1;i<n;i++)
	{
		long long l=i,sum=0,num=0;
		while(sum<=m&&l<n)
		{
			num++;
			sum+=c[l].ch*num;
			l++;
		}
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}

