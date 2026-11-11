#include <iostream>
#include <cstdio>
using namespace std;

int N;
string str = "";

void solve()
{
	cin >> N; int cnt = 0;
	for(int i = 1; i <= N; i++)
	{
		int ast; char cst; cin >> ast >> cst;
		for(int j = 1; j <= ast; j++)
			str += cst;
	}
	long long t = str.size() >> 1;
	for(long long i = 0; i < t; i++)
		if(str[i] != str[str.size() - 1 - i]) cnt++;
	cout << cnt;
}

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	solve();
	return 0;
}

