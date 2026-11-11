#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 3e5 + 10;
int ans[MAXN];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	queue <int> qhand;
	for(int i = 1; i <= n; i++)
	{
		int ai;
		cin >> ai;
		qhand.push(ai);
	}
	for(int i = 1; i <= n; i++)
	{
		queue <int> qtable;
		int l = 0;
		for(int j = 1; j <= i - 1; j++)
		{
			l++;
			qhand.push(qhand.front());
			qhand.pop();
		}
		int len = qhand.size() - l;
		for(int j = 1; j <= len; j++)
		{
			int k = 0;
			while(qtable.front() != qhand.front() and k < qtable.size())
			{
				qtable.push(qtable.front());
				qtable.pop();
				k++;
			}
			int ll = qtable.size();
			while(k < ll)
			{
				qtable.pop();
				k++;
			}
			qtable.push(qhand.front());
			qhand.push(qhand.front());
			qhand.pop();
		}
		while(!qtable.empty())
		{
			ans[qtable.front()]++;
			qtable.pop();
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
