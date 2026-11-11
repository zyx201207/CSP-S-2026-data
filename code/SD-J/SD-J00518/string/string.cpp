#include<bits/stdc++.h>
using namespace std;
//68
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, step = 0;
	cin >> n;
	string s = "";
	for(int i = 1; i <= n; i++)
	{
		long long a;
		char c;
		cin >> a >> c;
		for(int j = 1; j <= a; j++)
		{
			s += c;
		}
		//cout << i << ": " << s << endl;
	}
	long long x = s.size();
	long long t = x / 2;
	//cout << s << endl;
	for(int i = 0; i <= t; i++)
	{
		if(s[i] != s[x - i - 1])
		{
			//cout << i << ": " << s[i] << "    " << s[s.size() - i - 1] << endl;
			step++;
		}
	}
	cout << step << endl;
	return 0;
}
