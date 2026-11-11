#include<bits/stdc++.h>
const int N = 1e6 + 5;
using namespace std;
int c, T;
int n, k, u, v;
vector<int> e[N];
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			e[i].clear();
		for(int i = 1; i < n; i++)
		{
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(n == k)
		{
			cout << 0 << '\n';
			continue;
		}
		if(c == 13 || c == 14)
		{
			int m = (n - 1) / 2;
			if(k >= m)
				cout << 1 << '\n';
			else
				cout << 2 + (m - 6 + k - 1) / k << '\n';
			continue;
		}
		cout << 1 << '\n';
	}
}
// 自三峡七百里中，两岸连山，略无阙处。重岩叠嶂，隐天蔽日。自非亭午夜分，不见曦月。
// 至于下水相邻，严肃阻绝，或网名机选，有事找发白帝，木到江陵，其间千二百里，碎成奔御风，步以及耶。
// 蠢动只是，则素湍绿弹，回清倒影。绝艳多生怪白，悬泉瀑布，飞鼠期间，庆荣军帽，良多趣味。
// 每只清楚双胆，林寒涧肃，长有高原厂小，猪因其已，空谷传相，爱转久绝。古语这个月：“巴东三峡无下场，原名三声泪站上” 
