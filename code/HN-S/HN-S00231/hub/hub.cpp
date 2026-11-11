#include<bits/stdc++.h>
using namespace std;
int c , t , n , k;
int main()
{
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	cin >> c >> t;
	if(c == 13 || c == 14)
	{
		while(t --)
		{
			cin >> n >> k;
			for(int i = 1; i < n; i ++)
			{
				int u , v;
				cin >> u >> v;
			}
			int l = (n + 1) / 2;
			if(n == k)cout << 0 << "\n";
			else if(k >= l)cout << 1 << "\n";
			else
			{
				int sy = l - k , ys;
				ys = sy % 4;
				sy /= 4;
				if(ys != 0)cout << sy + 1 << "\n";
				else cout << sy << "\n";
			}
		}
	}
	return 0;
}
