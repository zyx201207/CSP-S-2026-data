#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	int ans=0;
	long long m;
	bool A=1,B=1;
	long long cz=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);
		if(A&&a[i]!=i) A=0;
		if(i==2) cz=a[2]-a[1];
		if(B&&i>2&&a[i]-a[i-1]!=cz) B=0;
	}
	if(A) 
	{
		long long tmp=0;
		for(int i=n;i>0;i--)
		{
			tmp=(long long)i*(i-1);
			if(tmp<=m)
			{
				ans=i;
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	if(B)
	{
		long long tmp=0;
		for(int i=1;i<=n;i++)
		{
			tmp+=(i-1)*cz;
			if(tmp>m)
			{
				break;
			}
			ans=i;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		int sum=1;
		long long tm=m;
		for(int j=i-1;j>0;j--)
		{
			tm-=a[i]-a[j];
			if(tm>=0) sum++;
			else break;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
/*
1 2 3 4 5 6 7 8 9
1-2 1
1-3 2 +1
1-4 3+2+1
1-n (n-1+1)*(n-1)
*/
/*
1 4 7 10 13 16
1-2 3
1-3 6+3
1-4 9+6+3
*/
