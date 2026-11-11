#include <bits/stdc++.h> 
using namespace std;

long long cnt;
string S1;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,a[20005];
	string S,c[20005];
	cin >> n;
	
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		for(long long j = 1;j <= a[i];j++)
		{
			S += c[i];
		}
	}
	
	for(long long i = S.size() - 1;i >= 0;i--)
	{
		S1 += S[i];
	}
	
	if(S1 == S)
	{
		cout << "0";
		return 0;
	}
	else
	{
		for(long long i = 1;i <= S1.size();i++)
		{
			cnt = 0;
			string S2 = S1;
			S2[i] = S2[S1.size() - i];
			cnt++;
			if(S2 == S)
			{
				cout << cnt;
				return 0;
			}
		}
	}
	return 0;
}
