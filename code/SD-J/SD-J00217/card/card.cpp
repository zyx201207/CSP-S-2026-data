#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005];
int f[300005];
bool p1an = 1;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		if (a[i] < a[i - 1] && i != 1) p1an = 0;
	}
	if (p1an){
		a[0] = a[1];
		for (int i = 1; i <= n; ++i){
			if (a[i] != a[i - 1]){
				cout << i << ' ';
			}
		}
		cout << n;
		return 0;
	}
	for (int i = 1; i <= n; ++i){
		set<int> s;
		stack<int> c;
		for (int j = i; j <= n; ++j){
			if (!s.count(a[j])){
				s.insert(a[j]);
				c.push(a[j]);
			}else{
				while (c.top() != a[j]){
					s.erase(c.top());
					c.pop();
				}
				if (!c.empty()) c.pop();
				c.push(a[j]);
			}
		}
		for (int j = 1; j <= m; ++j){
			if (s.count(j)){
				f[j]++;
			}
		}
	}
	for (int i = 1; i <= m; ++i){
		printf("%d ", f[i]);
	}
	return 0;
}
