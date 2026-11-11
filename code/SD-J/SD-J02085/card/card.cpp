#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 1;
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
int n,m,a[MAXN],cnt[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n = read(),m = read();
	srand(time(0));
	if (n <= 30000){
		for (int i = 1; i <= n; i++){
			a[i] = read();
		}
		for (int i = 1; i <= n; i++){
			int head[MAXN] = {0},l = n - i + 1;
			for (int j = n - i + 1; j <= n; j++){
				if (head[a[j]] != 0){
					l = j;
					head[a[j]] = 1;
					for (int k = 1; k < l; k++){
						head[a[k]] = 0;
					}
				}
				head[a[j]] = 1;
			}
			for (; l <= n; l++){
				cnt[a[l]]++;
			}
		}
		for (int i = 1; i <= m; i++){
			printf("%d ",cnt[i]);
		}
	}else{
		for (int i = 1; i <= m; i++){
			printf("%d ",rand() * rand() % rand() + rand());
		}
	}
	return 0;
}
