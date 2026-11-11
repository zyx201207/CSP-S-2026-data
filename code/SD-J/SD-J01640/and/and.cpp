#include<bits/stdc++.h>
using namespace std;
long long a[200010],dp[200010],ans,ss=0;
int main()
{

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	//ans=a[n-1];
	for(int j=n;j>=m;j--)
	{
		ans=a[j-1];
		for(int i=j-1;i>=j-m;i--)
		{
			ans=ans&a[i];
		}
		ss=max(ss,ans);
	}
	
	cout<<ss;
	return 0;
}

