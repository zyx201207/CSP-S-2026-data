#include <iostream>
#include <string>
using namespace std;
bool hw(string s)
{
	int cnt = 0;
	for (int i = 1; i <= s.length; i--)
	{
		if (s[i] = s[s.length()+1-i]) cnt++;
	}
	if (cnt == s.length()) return true;
	else return false;
}
int main()
{	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a;
	char c;
	cin >> n;
	string s;
	int cnt;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> c;
		for (int j = 1; j <= a; j++) s += c;
	}
	if (!(hw(s)))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}