#include<bits/stdc++.h>
using namespace std;
const long long N = 500005;
stack<char> sta;
long long n;
char c[N];
long long a[N];
string s;
long long ans = 0;
int main()	
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> n;
 	long long sum;
 	for(long long i = 1; i <= n; i ++)
 	{
 	
 		cin >> a[i];
 		if(i == 1) sum = a[1];
 		else 
 		{
 			sum = __gcd(sum, a[i]);
		 }
 		cin >> c[i];
	 }
	 for(long long i = 1; i <= n; i ++)
	 {
	 	for(long long j = 1; j <= a[i] / sum; j ++)
	 	{
	 		s += c[i];
		 }
	 }
	
	long long tmp = s.size();
	if(tmp % 2 != 0)
	{
		long long l = tmp / 2 + 1;
		for(long long i = 1; i < l; i ++)
		{
			sta.push(s[i - 1]);
		}
		for(long long i = l; i < tmp; i ++)
		{
			if(s[i] != sta.top())
			{
				ans ++;
			}
			sta.pop();
		}
	}
	else
	{
		long long l2 = tmp / 2;
		for(long long i = 1; i <= l2; i ++)
		{
			sta.push(s[i - 1]);
		}
		for(long long i = l2; i < tmp; i ++)
		{
			if(s[i] != sta.top())
			{
				ans ++;
			}
			sta.pop();
		}
	}
	cout << ans * sum;
    return 0;
}
