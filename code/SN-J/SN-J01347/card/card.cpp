#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;
int n, m, a[500005], b[300005];
deque<int> dq;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++){
		bool gg[m+5] = {false};
		for (int j = i;j <= n;j++){
			if (gg[a[j]]){
				while (dq.back() != a[j] && !dq.empty())
					dq.pop_back();
				if (!dq.empty()) dq.pop_back();
			}
			dq.push_back(a[j]);
			gg[a[j]] = true;
		}
		bool vis[m+5] = {false};
		while (!dq.empty()){
			if (!vis[dq.front()]){
				b[dq.front()]++;
				vis[dq.front()] = true;
				dq.pop_front();
			}
		}
		dq.clear();
	}
	for (int i = 1;i <= m;i++)
		cout << b[i] << ' ';
	return 0;
}
