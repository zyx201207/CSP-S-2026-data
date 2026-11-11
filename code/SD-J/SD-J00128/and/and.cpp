#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m, a[N], c[N], ans;
bool b[N];

void dfs(int d){
	if(d == m + 1){
		int num = c[1];
		for(int i = 1; i <= m; i++){
			num = num & c[i];
		}
		ans = max(ans, num);
		return;
	}
	for(int i = 1; i <= n; i++){
		if(b[i] == 0){
			c[d] = a[i];
			b[i] = 1;
			dfs(d + 1);
			b[i] = 0;
		}
	}
}

int main(){
	//*
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	//*/
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	dfs(1);
	printf("%d", ans);
	return 0;
}


