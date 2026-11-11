#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	int a;
	string b;
	int c = 0;
	for (int i = 0;i < n;i++)
	{
		cin >> a >> b;
		for (int j = 0;j < a;j++){
			s += b;
		}
		c += a;
	}
	c = c / 2 + 1;
	int m = 0;
	for (int i = 0;i < c;i++)
	{
		if (s[i] != s[c + i])
		{
			m++;
		}
	}
	cout << m - 1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
