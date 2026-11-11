#include<bits/stdc++.h>
using namespace std;

const int N = 200010;
int n;
long long a[N], len, ll, lr, ans;
char s[N];
bool flag = 1;

int main(){
	//*
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	//*/
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int x;
		char c;
		scanf("%d %c", &x, &c);
		while(x--){
			l++;
			s[l] = c;
		}
	}
	for(int i = 1; i <= n / 2 + 1; i++){
		if(s[i] != s[n - i + 1]){
			ans++;
		}
	}
	printf("%lld", ans);
	return 0;
}


