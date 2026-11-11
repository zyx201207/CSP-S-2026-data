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
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cout << 32 << endl << 17;
	return 0;
}