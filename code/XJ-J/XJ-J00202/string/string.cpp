#include<bits/stdc++.h>
using namespace std;
const long long N = 1e6;
long long n, a[N], sum = 0, k = 0;
char c[N];
string s = "";
int main() 
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		for(long long j = 1; j <= a[i]; j++)
		{
			s += c[i];
			k++;
		}
	}
	for(long long i = 0; i <= k/2; i++)
	{
		if(s[i] != s[n+1-i])	sum++;
	}
	cout << sum;
	return 0;
}
