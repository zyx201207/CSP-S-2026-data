#include <bits/stdc++.h>
#include <cstring>
using namespace std;


long long k(string r)
{
	long long i = 0;
	long long cnt = 0;
	while(i <= int(r.size() - i - 1))
	{
		if(r[i] != r[r.size() - i - 1])
		{
			cnt++;
		}
		i++;
	}
	return cnt;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	for(long long i = 1;i <= n;i++)
	{
		long long x;
		cin >> x;
		string t;
		cin >> t;
		for(long long j = 1;j <= x;j++)
		{
			s+=t;
		}
	}
	
	
	cout << k(s) << endl;
	
	return 0;
}















