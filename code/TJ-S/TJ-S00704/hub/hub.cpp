#include<bits/stdc++.h>
using namespace std;
int u[1000010], v[1000010];
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	scanf("%d %d", &c, &t);
	for(int i = 1; i <= t; i++){
		int n, k;
		scanf("%d %d", &n, &k);
		for(int i = 1; i <= n; i++){
			scanf("%d %d", &u[i], &v[i]);
		}
	}
} 
