#include <bits/stdc++.h>
#include <random>
#include <ctime>
using namespace std;
std::random_device rd;
mt19937 gen(time(0));
int c, n, m, d, q;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	long long k = n * m * d * q;
	uniform_int_distribution<>d (1, (c + k ) );
	for(int i = 1; i <= q; i++) cout << d(gen) << '\n';
	return 0;
}
