#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int qwq;
	cin >> qwq;
	int linen, stop, maxp, r;
	cin >> linen >> stop >> maxp >> r;
	int stht[stop];
	for (int i = 0; i < stop; i++) cin >> stht[i];
	int line[linen][5][2];
	int k[linen];
	for (int i = 0; i < linen; i++)
	{
		cin >> k[i];
		for (int j = 0; j < k[i]; j++)
		{
			cin >> line[i][j][0] >> line[i][j][1];
		}
	}
	int begin, final;
	for (int i = 0; i < r; i++)
	{
		cin >> begin >> final;
		int head = 1;
		int tail = 1;
		int a[linen][2];
		int b[linen][2];
		for (int j = 0; j < linen; j++)
		{
			for (int o = 0; o < k[j]; o++)
			{
				if (line[j][o][0] == begin)
				{
					a[head][0] = j;
					a[head][1] = line[j][o][1];
					head++;
				}
				else if (line[j][o][0] == final)
				{
					b[tail][0] = j;
					b[tail][1] = line[j][o][1];
				}
			}
		}
		int takes[head] = {0};
		int oo = 0;
		for (int j = 0; j < head; j++)
		{
			for (int o = 0; o < tail; o++)
			{
				for (int ii = 0; ii < k[j]; ii++)
				{
					for (int jj = 0; jj < k[o]; jj++)
					{
						if (line[j][ii][0] == line[o][jj][0])
						{
							takes[oo] += stht[line[j][ii][0]] + stht[line[o][jj][0]] + line[j][ii][1] + line[o][jj][1];
							oo++;
						}
					}
				}
			}
		}
		sort(takes, takes + oo);
		cout << takes[0] << endl;
	}
	return 0;
}
