#include <bits/stdc++.h>
using namespace std;
int n;
long long cnt = 0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	if(n == 1)
	{
		int a;
		char b;
		cin >> a >> b;
		cout << 0;
		return 0;
	}
	bool m = 1;
	char c;
	for(int i = 0;i < n;i++)
	{
		int a;
		char b;
		cin >> a >> b;
		if(i==0) c = b;
		if(c != b) m = 0;
		cnt += a;
	}
	if(m == 1)
	{
		cout << 0;
		return 0;
	}
	cout << cnt / 2;
	return 0;
}

