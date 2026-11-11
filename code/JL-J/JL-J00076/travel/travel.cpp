#include <bits/stdc++.h>
using namespace std;
bool flag, n, a, b;
int x, y;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char c1[10], c2[10], s1[10], s2[10];
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i = 0; i < 2; i++)
	{
		if(c1[0] == c2[0] && c1[1] == c2[1])
		{
			flag = true;
		}
	}
	if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
	{
		x = 1;
	}
	else
	{
		x = 2;
	}
	
	if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
	{
		y = 1;
	}
	else
	{
		y = 2;
	}
	
	if(flag)
	{
		if(s1[0] == s2[0] && s1[1] == s2[1])
		{
			n = true;
		}
		if(n == true && x == y)
		{
			a = true;
		}
		if(n == true && a == true && (abs(s1[2] - s2[2]) == 1))
		{
			
			b = true;
		}
	}		
	if(flag) cout << 1;
	else cout << 0;
	
	if(n) cout << 1;
	else cout << 0;
	
	if(a) cout << 1;
	else cout << 0;
	
	if(b) cout << 1;
	else cout << 0;
	return 0;
}
