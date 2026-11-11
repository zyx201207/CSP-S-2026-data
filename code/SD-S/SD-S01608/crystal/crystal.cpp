#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5E5 + 1;
//const int LEFT = -1e12;
const int LIMIT_NUM = 100;
inline long long read(){
	long long f = 1,x = 0;
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
long long n,m,a[MAXN],ans,newa[MAXN],step,ji;
bool all_less_hundred,special_judge_A,special_judge_B;
long long check(long long num,long long value){
	long long cnt = 0,ans = 0;
	for (int i = 1; i <= n; i++){
		if (a[i] > num){
			continue;
		}
		newa[++cnt] = num - a[i];
	}
	sort(newa + 1,newa + cnt + 1);
	for (int i = 1; i <= cnt; i++){
		if (value >= newa[i]){
			ans++;
			value -= newa[i];
		}else{
			break;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	srand(time(0));
	n = read(),m = read();
	for (int i = 1; i <= n; i++){
		a[i] = read();
		if (abs(a[i]) > LIMIT_NUM){
			all_less_hundred = true;
		}
		if (i > 2 && a[i - 1] - a[i - 2] != a[i] - a[i - 1]){
			special_judge_B = true;
		}
		if (a[i] != i){
			special_judge_A = true;
		}
	}
	if (!all_less_hundred && n <= 5000){
		for (long long i = -100; i <= 100; i++){
			ans = max(ans,check(i,m));
		}
		printf("%lld",ans);
	}else if (!special_judge_A){
		for (int i = n; i >= 1; i--){
			if (m >= n - i){
				ans++;
				m -= (n - i);
			}
			else break;
		}
		printf("%lld",ans);
	}else if (!special_judge_B){
		if (a[2] - a[1] >= 0){
			for (int i = n; i >= 1; i--){
				if (m >= a[n] - a[i]){
					ans++;
					m -= (a[n] - a[i]);
				}
				else break;
			}
			printf("%lld",ans);
		}else{
			for (int i = 1; i <= n; i++){
				if (m >= a[1] - a[i]){
					ans++;
					m -= (a[1] - a[i]);
				}
				else break;
			}
			printf("%lld",ans);
		}
	}else if (n <= 5000){
		for (int i = 1; i <= n; i++){
			ans = max(ans,check(a[i],m));
		}
		printf("%lld",ans);
	}else{
		printf("%d",rand() * rand() % rand() * rand() / rand() + rand());
	}
	return 0;
} 
