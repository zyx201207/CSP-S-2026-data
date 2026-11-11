#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main ()
{
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	scanf ("%d", &n);
	while (n --)
	{
		int x;
		scanf ("%d", &x);
		char a;
		scanf ("%c ", &a);
		for (int i = 1; i <= x; i ++) s = s + a;
	}
	int sz = s.size ();
	printf ("%d", sz / 2);
	return 0;
}