#include<bits/stdc++.h>
using namespace std;
long long n,m,s,ans,ma;
long long a[100000000],b[100000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int m1;
	for(int i=0;i<n;i++)
	{
		ma=0;
		m1=m;
		for(int j=i-1;j>=0&&m1>=a[i]-a[j];j--)
		{
			ma++;
			m1-=a[i]-a[j];
		}
		ans=max(ma+1,ans);
	}
	cout<<ans;
} 