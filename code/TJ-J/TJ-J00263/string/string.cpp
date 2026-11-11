#include <iostream>
#include <queue>
using namespace std;
struct str{
	long long biao = 0;
	char fu;
};
long long n, sum, sum1, ans;
str sin[200005];
queue <str> in;
queue <str> rin;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> sin[i].biao;
		cin >> sin[i].fu;
		sum += sin[i].biao;
	}
	sum = (sum + 1) / 2;
	sum1 = sum;
	for (int i = 1;i <= n;i++)
	{
		in.push(sin[i]);
		rin.push(sin[n + 1 - i]);
	}
	while (!(in.empty() && rin.empty()))
	{
		if (rin.front().biao > in.front().biao)
		{
			if (rin.front().fu != in.front().fu)
			{
				ans += in.front().biao;
			}
			rin.front().biao -= in.front().biao;
			in.pop();
		}
		else if(rin.front().biao < in.front().biao)
		{
			if (rin.front().fu != in.front().fu)
			{
				ans += rin.front().biao;
			}
			in.front().biao -= rin.front().biao;
			rin.pop();
		}
		else
		{
			if (rin.front().fu != in.front().fu)
			{
				ans += rin.front().biao;
			}
			rin.pop();
			in.pop();
		}
	}
	cout << ans / 2;
	return 0;
}
