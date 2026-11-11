#include<iostream>
#include<vector>
#include<stack>
#define int long long

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	std::cin>>n>>m;
	std::vector<int> a(n+1, 0);
	for (int i=1; i<=n; i++)
		std::cin>>a[i];
	std::vector<int> ans(m+1, 0);
	for (int i=1; i<=n; i++) {
		std::stack<int> s;
		std::vector<bool> ins(m+1, false);
		for (int j=i; j<=n; j++) {
			if (ins[a[j]])
				while (!s.empty() and ins[a[j]]) {
					ins[s.top()]=false;
					s.pop();
				}
			s.push(a[j]);
			ins[a[j]]=true;
		}
		while (!s.empty())
			ans[s.top()]++, s.pop();
	}
	for (int i=1; i<=m; i++)
		std::cout<<ans[i]<<' ';
	return 0;
}
