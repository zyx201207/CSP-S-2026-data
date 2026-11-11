#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
inline int read(){
	int x = 0, y = 1;
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
long long a[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n = read(), m = read();
	long long maxn = 0, x = 0, y = 0;
	for(int i = 1; i <= n; i++){
		a[i] = read();
	}
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++){
		x += y * (a[i] - a[i-1]);
		y++;
//		cout << x << " " << y << endl; 
		if(x > m){
			while(1){
				x -= a[i] - a[i-y+1];
				y--;
//				cout << x << " " << y << endl; 
				if(x <= m){
					break;
				}
			}
		}
		maxn = max(maxn, y);
	}
	cout << maxn;
	return 0;
}
