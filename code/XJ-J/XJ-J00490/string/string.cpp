#include<bits/stdc++.h>
using namespace std;
long long n , a , m;
string s , c;
int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a >> c;
			s += c * a;
	}
	for(int i = 1; i <= n; i++)
	{
		if(s[i] != s[n - i + 1])
		{
			m++;
		}
	}
	cout << m;
	return 0;
}