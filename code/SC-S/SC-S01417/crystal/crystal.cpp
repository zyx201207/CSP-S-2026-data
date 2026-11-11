#include<bits/stdc++.h>
const int SZ = 1 << 16;
char ib[SZ], *is = ib, *it = ib, ob[SZ], *os = ob, *ot = ob + SZ, ostk[50];
#define Flush() (fwrite(ob, 1, os - ob, stdout), os = ob)
#define gc() (((is == it) && (it = ib + fread(is = ib, 1, SZ, stdin))), ((is == it) ? EOF : *is++))
#define pc(ch) (((os == ot) && Flush()), *os++ = ch)
#define END return Flush(), fflush(stdout), fclose(stdin), fclose(stdout), 0
typedef long long ll;
template <typename T> inline void read(T &x){
	x = 0;
	int ch = gc();
	bool flg = false;
	while((ch < '0' || ch > '9') && ch != EOF){
		flg |= ch == '-';
		ch = gc();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + (ch ^ 48);
		ch = gc();
	}
	x = flg ? -x : x;
}
template <typename T> inline void write(T x, char c = 0){
	if(x == 0){
		pc('0');
		if(c) pc(c);
		return;
	}
	if(x < 0){
		pc('-');
		x = -x;
	}
	int top = 0;
	while(x){
		ostk[++top] = (x % 10) | 48;
		x /= 10;
	}
	while(top) pc(ostk[top--]);
	if(c) pc(c);
}
// #undef DEBUG
// #undef STDIO
#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
const int N = 5e5 + 10;
int n, ans;
ll m, a[N], sum;
int main(){
	#ifndef STDIO
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	#endif
	read(n), read(m);
	for(int i = 1; i <= n; i++){
		read(a[i]);
	}
	std::sort(a + 1, a + n + 1);
	sum = 0;
	for(int i = 1, ptr = 1; i <= n; i++){
		sum += a[i];
		while((i - ptr + 1) * a[i] - sum > m){
			sum -= a[ptr];
			ptr++;
		}
		// debug("i = %d, ptr = %d, sum = %lld\n", i, ptr, sum);
		ans = std::max(ans, i - ptr + 1);
	}
	write(ans, '\n');
	END;
}