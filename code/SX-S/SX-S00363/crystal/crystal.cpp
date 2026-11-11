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
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	long long n, m;
	n = read();
	m = read();

	long long list[n];
	for(long long i = 0;i < n;i++){
		list[i] = read();
	}

	sort(list, list + n);

	long long all = 0;
	for(long long i = 0;i < n;i++){
		all += list[i];
	}
	double ba = all /m;

	long long cnt = 0;
	for(long long i = 0;i < n;i++){
		if((double)list[i] > ba){
			cnt = i++;
			break;
		}
	}

	cout << cnt;
	return 0;
}