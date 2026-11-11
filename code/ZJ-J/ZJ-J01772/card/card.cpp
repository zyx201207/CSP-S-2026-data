#include <bits/stdc++.h>
using namespace std;
int n, m, a[500001], ans[300001];
bool f = true, vis[300001];
stack<int>s;
int main(){
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	scanf ("%d%d" ,&n ,&m);
	for (int i = 1;i <= n;i ++){
		scanf ("%d" ,&a[i]);
		if (i > 1 && a[i - 1] > a[i]){
			f = false;
		}
	}
	if (f){
		for (int i = 1;i <= n;i ++){
			if (i > 1 && a[i] != a[i - 1]){
				printf ("%d " ,i - 1);
			}
		}
		printf ("%d" ,n);
		return 0;
	}
	for (int i = 1;i <= n;i ++){
		memset(vis, false, sizeof(vis));
		for (int j = i;j <= n;j ++){
			if (vis[a[j]]){
				while (s.size() && s.top() != a[j]){
					vis[s.top()] = false;
					s.pop();
				}
			} else {
				vis[a[j]] = true;
				s.push(a[j]);
			}
		}
		while (s.size()){
			ans[s.top()] ++;
			s.pop();
		}
	}
	for (int i = 1;i <= m;i ++){
		printf ("%d " ,ans[i]);
	}
	return 0;
}
