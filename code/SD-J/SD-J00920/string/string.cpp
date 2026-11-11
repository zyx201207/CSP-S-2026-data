#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ulli unsigned lli
#define f(i, a, b) for(lli i = a; i <= b; i++)

const ulli MAX_SIZE = 2e5 + 5;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	string s;
	
	lli t, n = 0, a, answer = 0;
	char c;
	
	cin >> t;
	f(i, 1, t)
	{
		cin >> a >> c;
		
		n += a;
		
		f(j, 1, a)
		{
			s += c;
		}
	}
	
	f(i, 0, n/2-1)
	{
		answer += s[i] != s[n - i - 1];
	}
	
	cout << answer << "\n";
	
	return 0;
}
