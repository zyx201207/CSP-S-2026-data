#include <bits//stdc++.h>
using namespace std;
int n, m, a[500005], sum[500005], b[500005], last[500005], show[500005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		last[i] = show[a[i]];
		show[a[i]] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		int len = 0;
		for(int j = i; j <= n; j++)
		{
			b[++len] = a[j];
			for(int k = 1; k < len; k++)
			{
				if(b[k] == b[len])
				{
					len = k;
				}
			}
		}
		for(int j = 1; j <= len; j++)
		{
			sum[b[j]]++;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << sum[i] << " ";
	}
	return 0;
}
/*#include <bits//stdc++.h>
using namespace std;
int n, m, a[500005], chf[500005], last[500005], show[500005], b[500005], sum[500005];
void change(int l, int r, int d)
{
	chf[l] += d;
	chf[r + 1] -= d;
	for(int i = 1; i <= n + 1; i++)
		cout << chf[i] << setw(3);
	cout << '\n';
}
int main(){
	//freopen("card.in", "r", stdin);
	//freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		b[i] = a[n - i + 1];
		last[i] = show[b[i]];
		show[b[i]] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		cout << last[i] << " ";
	}
	cout << '\n';
	for(int i = 1; i <= n; i++)
	{
		cout << b[i] << " ";
	}
	cout << '\n';
	for(int i = 1; i <= n; i++)
	{
		change(1, i, 1);
		if(last[i] != 0)
		{
			change(last[i] + 1, i, -1);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		a[i] = a[i - 1] + chf[i];
		sum[b[i]] = max(sum[b[i]], a[i]);
	}
	for(int i = 1; i <= m; i++)
	{
		cout << sum[i] << " ";
	}
	return 0;
}
*/
