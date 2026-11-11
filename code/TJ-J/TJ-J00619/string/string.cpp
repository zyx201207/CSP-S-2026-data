#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		long long num;
		char a;
		cin>>num>>a;
		for(int j=1;j<=num;j++)
		{
			s+=a;
		}
		sum+=num;
	}
	long long ans=0;
	sum--;
	for(int i=0;i<=sum/2;i++)
	{
		if(s[i]!=s[sum-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
