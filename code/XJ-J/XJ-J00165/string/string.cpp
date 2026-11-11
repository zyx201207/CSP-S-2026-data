#include<bits/stdc++.h>

using namespace std;

int n, m, a;
char c, s[40000000009];
bool t = true;
long long ans = 0, k = 0;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d %c", &a, &c);
		for(int i = 1; i <= a; i++)
			s[++k] = c;
	}
	for(int i = 1; i <= k - 1; i++)
		if(s[i] != s[i + 1])
			t = false;
	if(t){
		printf("0\n");
		return 0;
	}
	for(int i = 1; i <= k / 2; i++)
		if(s[i] != s[k - i + 1])
			ans++;
	printf("%d\n", ans);
	return 0;
}
