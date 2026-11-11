#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	long long m = 0;
	string S = "";
	long long a[200005];
	string c[200005];
	cin >> n;
	for(long long i = 0; i < n; i++)
	{
		cin >> a[i] >> c[i];
		for (long long j = 0; j < a[i]; j++)
		{
			S += c[i];
		}
	}
	long long len = S.length();
	for(long long i = 0; i < len/2; i++)
	{
		if(S[i] != S[len-i-1])
		{
			m++;
		}
	}
	cout << m;
	return 0;
}
