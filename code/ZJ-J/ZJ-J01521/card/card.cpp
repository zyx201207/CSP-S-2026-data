#include<bits/stdc++.h>
using namespace std;
int n, m, a[500010], ans[500010];
bool flag[500010];
stack<int> c;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(flag[a[j]]){
				while(c.top() != a[j]){
					flag[c.top()] = 0;
					c.pop();
				}
				c.pop();
			}
			c.push(a[j]);
			flag[a[j]] = 1;
		}
		for(int i = 1; i <= m; i++){
			if(flag[i]) ans[i]++;
			flag[i] = 0;
		}
	}
	for(int i = 1; i <= m; i++){
		printf("%d ", ans[i]);
	}
	return 0;
}
