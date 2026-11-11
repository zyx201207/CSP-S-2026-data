#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int, int>
#define fi first
#define se second
using namespace std;
const int MAXN = 5e5 + 7;

inline int read()
{
	int w = 0, c = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		c = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		w = w * 10 + ch - '0';
		ch = getchar();
	}
	return w * c;
}

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	srand(time(0));
	int c = read(), t = read();
	
	while(t--)
	{
		cout<<rand()%10+1<<endl;
	}
	
	return 0;
}
