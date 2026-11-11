#include<bits/stdc++.h>
using namespace std;
int n, m, cnt;
int s[500010], a[500010], cn[300010];
int check(int x){
	for(int i = 1; i <= cnt; i++){
		if(x == s[i]) return i;
	}
	return 0;
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		cnt = 0;
		memset(s, 0, sizeof(s));
		for(int j = i; j <= n; j++){
			int f = check(a[j]);
			if(f == 0) s[++cnt] = a[j];
			else cnt = f;
		}
		for(int j = 1; j <= cnt; j++){
			cn[s[j]]++;
		}
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		if(cn[a[i]] != n + 1){
			printf("%d ", cn[a[i]]);
			cn[a[i]] = n + 1;
		}
	}
	return 0;
}