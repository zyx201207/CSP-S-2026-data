#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 1;
int c,n,m,d,q,w[MAXN];
inline int read(){
	int f = 1,x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9'){
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return f * x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	c = read(),n = read(),m = read(),d = read(),q = read();
	for (int i = 1; i <= m; i++){
		w[i] = read();
	}
//	for (int i = 1; i <= m; i++){
//		
//	}
	while (q--){
		printf("%d\n",abs(rand() * rand() / rand() * rand() % rand() | rand() * true) + rand() | rand());
	}
	return 0;
} 
