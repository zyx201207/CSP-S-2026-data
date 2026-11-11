#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long res = 0ll;
	long long a = 1ll;
	char ch = getchar();
	while (ch < '0' || ch > '9'){
		if (ch == '-') a = -1ll;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9'){
		res = res * 10ll + ch - '0';
		ch = getchar();
	}
	return res * (long long)a;
} 
int c;
int t;
int n;
int k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c = read();
	t = read();
	while (t--){
		n = read();
		k = read();
		for (int i = 1;i < n;i++) int aa = read(),bb = read();
		if (c == 13 || c == 14) {
			if (k == 1) printf("%d\n",(n-1)/2);
			if (n % 4 == 1){
				if (k % 4 == 2) {
					printf("%d\n",(((n - 1) >> 2) + 1) - ((k + 2) >> 2));
				}else printf("%d\n",(((n - 1) >> 2) + 1) - ((k + 2) >> 2) + 1);
			}
			else if (n % 4 == 3){
				if (k % 4 == 3){
					printf("%d\n",((n+1) >> 2) - ((k + 1) >> 2));
				}
				else printf("%d\n",((n+1) >> 2) - ((k + 1) >> 2) + 1);
			}
		}
	}
	return 0;
}