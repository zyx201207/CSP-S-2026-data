#include <bits/stdc++.h>
using namespace std;
char S[200005];
long long Num[200005], N, ans;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>N;
	for (long long i = 1; i<=N; i++)
	{
		cin>>Num[i]>>S[i];
	}
	if (N%2)
	{
		Num[N/2+1]--;
	}
	long long L = 1, R = N;
	while (L < R)
	{
		long long min_len = min(Num[L], Num[R]);
		if (S[L] != S[R])
		{
			ans+=min_len;
		}
		Num[L] -= min_len;
		Num[R] -= min_len;
		if (Num[L] == 0) L++;
		if (Num[R] == 0) R--;
	}
	cout<<ans;
	return 0;
}