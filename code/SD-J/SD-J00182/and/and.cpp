#include<bits/stdc++.h>
using namespace std;

int n, m;
int dp[200001];
int a[200001];
bool b[200001];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		dp[1] = max(dp[1], a[i]);
		if(dp[1] == a[i]){
			b[i] = 0;
		}
	}
	for(int i = 1; i < m; i++){
		for(int j = 1; j <= n; j++){
			dp[i + 1] = max(dp[i] & a[j], dp[i + 1]);
			printf("%d\n", 31 & 1);
		}
	}
	printf("%d", dp[m]);
	return 0;
}
