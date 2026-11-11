#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define pb push_back

inline void read(LL &x){
	x = 0;int f = 1, c = getchar();
	while (c < 48 || c > 57){
		if (c == '-') f = -1;
		c = getchar(); 
	}
	while (c >= 48 && c <= 57){
		x = (x << 3) + (x << 1) + (c & 15);
		c = getchar();
	}
	x *= f;
}
LL n, d, x[2000010], cnt[2000010], f[2000010], s[2000100];
void work_6(){
	
	read(n);
	read(d);
	for (int i = 1;i <= n;i ++)
		read(x[i]);
	LL ans = 0;
	for (int i = 1;i <= n;i ++){
		for (int j = 1;j <= n;j ++)
			cnt[j] = 0, f[j] = 1e18;
		f[i] = 0;
		cnt[i] = 1;
		for (int j = i + 1, last = i;j <= n;j ++){
			while (x[j] - x[last] > d && last <= j) last ++;
			int r = upper_bound(f + last, f + j, f[last]) - f - 1;
//			cout << j << " " << last << " " << r << endl;
			cnt[j] = cnt[r] - cnt[last - 1];
			if (cnt[j] == 2) ans ++;
			cnt[j] += cnt[j - 1];
			if (x[j] - x[last] <= d)
				f[j] = f[last] + 1;
			else break;
		}
//		cout << endl;
	}
	cout << ans << "\n";
	
}

void work(){
	
	read(n);
	read(d);
	for (int i = 1;i <= n;i ++)
		read(x[i]);
	
	LL ans = 0;
	for (int i = 1;i <= n;i ++)
		s[i] = cnt[i] = 0, f[i] = 1e18;
	f[1] = 1;
	cnt[1] = 1;
	s[1] = 1;
	for (int i = 2, last = 1;i <= n;i ++){
		while (x[i] - x[last] > d && last < i) last ++;
		
		int r = upper_bound(f + last, f + i, f[last]) - f - 1;
		cnt[i] = s[r] - s[last - 1];
		if (cnt[i] == 2){
			cout << n - i + 1 << endl;
			return ;
		}
		s[i] = cnt[i] + s[i - 1];
		
		if (x[i] - x[last] <= d)
			f[i] = f[last] + 1;
	}
	cout << ans << endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	LL c, t;
	read(c);read(t);
	if (c <= 10){
		while (t --) work_6();
		return 0;
	}
	while (t --) work();
	
//	int a[18] = {3, 4, 5, 5, 5, 6, 7, 8, 9, 9};
//	for (int i = 1, x;i <= 30;i ++){
//		scanf ("%d", &x);
//		cout << upper_bound(a, a + 10, x) - a << endl; 
//	}
	
	return 0; 
}
