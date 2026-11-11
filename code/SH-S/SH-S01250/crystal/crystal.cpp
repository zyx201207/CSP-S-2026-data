#include<bits/stdc++.h>
using namespace std;
long long s[500010],a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cnt;
	s[1]=0;
	for(int i=2;i<=n;i++)
	{		
		s[i]=(a[i]-a[i-1])*(i-1)+s[i-1];
	}
	for(int i=2;i<=n;i++)
	{
		if(s[i-1]<=m&&s[i]>m)
		{
			cnt=i-1;
		}
	}
	cout<<cnt;
	return 0;
}
