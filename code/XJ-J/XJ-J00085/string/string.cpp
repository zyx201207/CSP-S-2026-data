#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a;
	long long n,sum=0,count=0;
	cin >> n;
	for(long long j=1;j<=n;j++)
	{
		long long s;
		char z;
		cin >> s >> z;
		sum+=s;
		for(long long i=1;i<=s;i++)
		{
			a+=z;
		}
	}
	for(long long i=sum/2;i<sum;i++)
	{
		if(a[i]==a[sum-i])
		{
			count++;
		}
	}
	if(sum%2==0)
	{
		cout << sum-count*2;
	}
	else
	{
		cout << sum-(count*2-1);
	}
	return 0;
}
