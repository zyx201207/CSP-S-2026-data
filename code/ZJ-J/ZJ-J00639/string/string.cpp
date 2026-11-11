#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
struct Node{
	int n;
	char ch;
};
Node a[MAXN];
Node b[MAXN];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, tn;
	string s = "";
	char ch;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d %c", &a[i].n, &a[i].ch);
		b[n - i + 1].n = a[i].n;
		b[n - i + 1].ch = a[i].ch;
	}
	int dexa = 1, dexb = 1;
	long long cnt = 0;
	while(dexb <= n && dexa <= n){
		if(a[dexa].n < b[dexb].n){
			if(a[dexa].ch != b[dexb].ch) cnt += a[dexa].n;
			b[dexb].n -= a[dexa].n;
			dexa++;
		}else if(a[dexa].n > b[dexb].n){
			if(a[dexa].ch != b[dexb].ch) cnt += b[dexb].n;
			a[dexa].n -= b[dexb].n;
			dexb++;
		}else{
			if(a[dexa].ch != b[dexb].ch) cnt += a[dexa].n;
			dexb++;
			dexa++;
		}
	}
	printf("%lld\n", (cnt / 2));
	return 0;
}