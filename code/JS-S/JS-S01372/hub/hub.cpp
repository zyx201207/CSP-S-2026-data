#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int c, t;

/*struct CCF
{
	int v;
	int u;
} G[N];*/

int main()
{
	//freeopen!!!
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n - 1; i++)
		{
			int a, b;
			cin >> a >> b;
			//G[i] = ({a, b});
		}
		cout << (n / k / 2) + (n / k) % 2 << endl;
	}
	return 0;
}
/*
 ceng jing cang hai nan wei shui
 chu que wu shan bu shi yun
*/
