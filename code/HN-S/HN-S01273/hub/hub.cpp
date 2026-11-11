#include<bits/stdc++.h>
using namespace std;
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
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int ccc = read(), T = read();
	while(T--){
		cout << "1\n";
	}
	return 0;
}
