#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t, n, k;
	scanf("%d%d", &c, &t);
	while(t--) {
		scanf("%d%d", &n, &k);
		printf("%d\n", n / k + 1);
	}
	return 0;
}
