#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
inline long long read(){
	long long x = 0, y = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-'){
			y = -1;
		}
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * y;
}
long long b[5001][5001], minn, l = 1;
long long a[N];
void work(int x, int y, int t){
	if(t >= minn){
		return ;
	}
	t++;
	for(int i = 1; i <= b[x][0]; i++){
		if(b[x][i] == y){
			if(minn == t){
				l++;
			}else if(minn > t){
				l = 1;
				minn = t;
			}
		}
		if(b[x][i] > y){
			return;
		}
		work(b[x][i], y, t);
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int ccc = read(), T = read();
	long long o;
	bool e = 1;
	while(T--){
		int n = read(), ans = 0;
		long long d = read();
		if(n <= 5000){
			for(int i = 1; i <= n; i++){
				b[i][0] = 0;
			}
		}
		for(int i = 1; i <= n; i++){
			a[i] = read();
			if(i == 2){
				o = a[i] - a[1];
			}
			if(i > 2 && o != a[i] - a[i-1]){
				e = 0;
			}
		}
//		for(int i = 1; i <= n; i++){
//			cout << i << ": ";
//			for(int j = 1; j <= b[i][0]; j++){
//				cout << b[i][j] << " ";
//			}
//			cout << '\n';
//		}
//		cout << e << '\n';
		if(e){
			o = d / o;
			if(o <= 1){
				cout << 0 << '\n';
				continue;
			}
			o = o * 2 - 1;
			if(o > n){
				cout << "0\n";
				continue;
			}
			cout << n - o << '\n';
			continue;
		}
		for(int i = 2; i <= n; i++){
			for(int j = i-1; j >= 1; j--){
//				cout << a[i] << " " << a[j] << " " << a[i] - a[j] << endl;
				if(a[i] - a[j] <= d){
					b[j][0]++;
					b[j][b[j][0]] = i;
				}else{
					break;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				minn = j-i;
				l = 1;
				work(i, j, 0);
				if(l == 2){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
