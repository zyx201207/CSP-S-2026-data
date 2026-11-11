#include <bits/stdc++.h>
using namespace std;
using lint = long long;
inline void fastread(int& x){
	x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
}
inline void fastprint(int x){
	if(x > 9) fastprint(x / 10);
	putchar(x % 10 + 48);
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	return 0;
}
