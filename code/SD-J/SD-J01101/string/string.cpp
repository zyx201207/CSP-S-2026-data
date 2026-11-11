#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	char s;
	long long a;
	string st;
	long long t = 1;
	for (int i = 1;i <= n;i++)
	{
		cin >> a >> s;
		while (a != 0)
		{
			st[t++] = s;
			a--;
		}
	}
	t--;
	long long l = 1,r = t;
	long long w = 0;
	
	for (int i = 1;i <= t/2;i++)
	{
		if (st[l] != st[r])
		{
			w++;
		}
		l++;
		r--;
	}
	cout << w;
	
	
	return 0;
} 
