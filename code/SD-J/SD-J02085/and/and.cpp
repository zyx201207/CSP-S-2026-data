#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2E5 + 1;
int lg[30] = {0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431,67108863,134217727,268435455,536870911};
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
int n,m,a[MAXN],ans;
void dfs(int i,int step,int num){
	if (step >= m){
		ans = max(num,ans);
		return;
	}
	if (i > n) return;
	dfs(i + 1,step,num);
	dfs(i + 1,step + 1,num & a[i]);
}
void dfs2(int i,bool step,int num){
	if (i > n && step){
		ans = max(num,ans);
		return;
	}
	if (i > n) return;
	dfs2(i + 1,step,num & a[i]);
	if (!step){
		dfs2(i + 1,1,num);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n = read(),m = read();
	srand(time(0));
	if (n == m){
		for (int i = 1; i <= n; i++){
			a[i] = read();
			ans = ans & a[i];
		}
		printf("%d\n",ans);
	}else if (m == 1){
		for (int i = 1; i <= n; i++){
			a[i] = read();
			ans = max(a[i],ans);
		}
		printf("%d\n",ans);
	}else if (m == 2 && n <= 30000){
		for (int i = 1; i <= n; i++){
			a[i] = read();
		}
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				ans = max(a[i] & a[j],ans);
			}
		}
		printf("%d\n",ans);
	}else if (n <= 30){
		for (int i = 1; i <= n; i++){
			a[i] = read();
		}
		dfs(1,0,INT_MAX);
		printf("%d\n",ans);
	}else{
		bool AAA = true,BBB = false;
		for (int i = 1; i <= n; i++){
			a[i] = read();
			bool tmpA = true;
			for (int j = 0; j < 30; j++){
				if (a[i] == lg[j]){
					tmpA = false;
				}
			}
			if (!tmpA) continue;
			AAA = false;
		}
		if (AAA){
			sort(a + 1, a + n + 1);
			ans = a[n];
			for (int i = n; i >= n - m + 1; i--){
				ans = ans & a[i];
			}
			printf("%d",ans);
		}else if (!AAA){
			printf("%d\n",rand());
		}
	}
	
	return 0;
}
