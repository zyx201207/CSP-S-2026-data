#include<bits/stdc++.h>
using namespace std;

inline long long read(){
	long long f = 1, m = 0;
	char x = getchar();

	while((x < '0')||(x > '9')){
		f = -1;
		x = getchar();
	}

	while((x > '0')&&(x < '9')){
		m = m * 10 + x - '0';
		x = getchar();
	}

	return m * f;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	long long c, t;
	c = read();
	t = read();

	for(long long i = 0;i < t;i++){
		long long n, d;
		n = read();
		d = read();

		long long list[n];
		for(long long j = 0;j < n;j++){
			list[j] = read();
		}

		long long dlt = list[1] - list[0];
		for(long long i = 1;i < n;i++){
			list[i] = list[i] - ((dlt - 1) * i);
		}
		d = d /dlt;

		long long num = (n - (n %dlt)) / dlt;
		cout << num << endl;
	}

	return 0;
}