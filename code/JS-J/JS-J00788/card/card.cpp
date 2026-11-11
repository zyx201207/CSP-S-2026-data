#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
const int M = 3e5 + 7;
int n, m;
int card_have[N];
int card_stack[N];
int card_appear_cnt[M];
int card_put_pos[M];
void print_card_stack(int n)
{
	for (int i = 1; i <= n ; i ++)
	{
		cout << card_stack[i] << ' ';
	}
	cout << endl;
}
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		cin >> card_have[i];
	}
	int card_stack_i = 0;
	for (int i = 1; i <= n; i ++)
	{
		memset(card_put_pos, -1, sizeof(card_put_pos));
		memset(card_stack, 0, sizeof(card_stack));
		card_stack_i = 0;
		for (int j = i; j <= n; j ++)
		{
			if (card_put_pos[card_have[j]] != -1)
			{
				card_stack_i = card_put_pos[card_have[j]] - 1;
				for (int k = card_put_pos[card_have[j]]; ; k ++)
				{
					if (card_stack[k] == 0)
					{
						break;
					}
					card_put_pos[card_stack[k]] = -1;
					card_stack[k] = 0;
				}
			}
			card_stack[++ card_stack_i] = card_have[j];
			card_put_pos[card_have[j]] = card_stack_i;
		}
		for (int i = 1; i <= card_stack_i; i ++)
		{
			card_appear_cnt[card_stack[i]] ++;
		}
	}
	for (int i = 1; i <= m; i ++)
	{
		cout << card_appear_cnt[i] << ' ';
	}
	cout << endl;
	return 0;
}