#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef __int128 i128;
const int N = 5e5 + 10;
i128 n, m;
i128 a[N];

i128 read (){
	i128 x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		x = x * 10 + (c - '0');
		c = getchar();
	}
	x *= f;
	return x;
}

void print(i128 x){
	if (x == 0) return ;
	print (x / 10);
	putchar (x % 10 + '0');
}


void write(i128 x){
	if (x < 0){
		putchar('-');
		x = -x;
	}
	if (x == 0){
		putchar('0');
	}else {
		print(x);
	}
	
	
}

signed main (){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = read();
	m = read();
	
	for (int i = 1; i <= n; i++){
		a[i] = read();
	} 
	sort (a + 1, a + n + 1);
	
	if (n == 1){
		write(1);
		return 0;
	} 
	i128 ans = 1;
	i128 tot = 0;
	i128 j = 1;
	for (i128 i = 1; i <= n; i++){
		tot += (a[i] - a[i - 1]) * (i - 1- j + 1);
		while (tot > m && j < i){
			tot -= a[i] - a[j];
			j ++;
		}
		ans = max (ans, i - j + 1);
	}
	
	write(ans);
	
	
	
	return 0;
}
/*
8
×î¶àm´Î 
10 10
1 8 5 4 3 7 511 523 774 114
1 3 4 5 7 8 114 511 523 774

4 + 3 + 1

*/
