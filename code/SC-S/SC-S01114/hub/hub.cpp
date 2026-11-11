#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+5;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--)
	{
		int n,k;
		cin >> n >> k;
		if (k >= n) cout << 0;
		else
		{
			n = n/2+1;
			if (k >= n-1) cout << 1;
			cout << (n-k+3-1)/3+1;
		}
	}
	return 0;
}
/*
10min:耶耶耶，我终于做出T1了
2h:我居然写出T2了！！！
4h:哦不，我还是不会T3T4
gg
希望有人做迷惑行为大赏时可以看到（doge 
*/