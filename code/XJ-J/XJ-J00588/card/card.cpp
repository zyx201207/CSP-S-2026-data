#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n, m, a[500005], f[500005], t[300005], tmp = 1;
int main(int argc, char** argv) {
	freopen("card.in", "r", stdin);
	freopen("card,out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++)
	{
		int cnt = 1, ans = 0;
		f[1] = a[1];
		for (int j = i; j <= n; j ++)
		{
			for (int k = 1; k <= cnt; k ++)
			{
				if (f[k] == a[j])
				{
					for (int h = k; h <= cnt; h ++)
					{
						f[h] = 0;
						cnt --;
					}
					break;
				}
			}
			cnt ++;
			f[cnt] = a[i];
		}
		int id[300005] = {};
		for (int j = 1; j <= cnt; j ++)
		{
			id[f[j]] = 1;
		}
		for (int j = 1; j <= m; j ++)
		{
			t[j] += a[j];
		}
	}
	for (int i = 1; i <= m; i ++)
	{
		cout << t[i] << ' ';
	}
	return 0;
}