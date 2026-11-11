#include <bits/stdc++.h>
using namespace std;

int s[100000005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt =0,now = 0,sum = 0;
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		int a;
		char c;
		cin >> a >> c;
		sum += a;
		s[now]+=c;
		s[a+now]-=c;
		now = a;
	}
	for(int i = 0;i<=sum;i++)
	{
		s[i] += s[i-1];
	}
	for(long long i = 0;i<sum/2;i++)
	{
		if(s[i]!=s[sum-i-1])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
