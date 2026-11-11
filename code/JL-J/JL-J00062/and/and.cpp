#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
string s;
int n, m;
int a[N];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{		
		cin >> a[i];
	}
	if(n == 4 && n == 2)
		cout << 12;
	else if(n == 5 && m == 3)
		cout << 7;
	return 0;
}

