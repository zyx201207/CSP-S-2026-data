#include<bits/stdc++.h>
using namespace std;
long long a;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> a;
	for(int i = 1;i <= a;i++)
	{
		int b;
		string ss;
		cin >> b >> ss;
		for(int j = 1;j <= b;j++)
		{
			s = s + ss;
		}
	}
	long long a = s.size();
	long long c = 0;
	for(int i = 0;i <= a/2-1;i++)
	{
		if(s[i] != s[a-i])
		{
			s[a - i] = s[i];
			c++;
		}
	}
	cout << c;
	return 0;
}