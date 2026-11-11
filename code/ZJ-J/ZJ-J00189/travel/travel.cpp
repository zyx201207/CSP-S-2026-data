#include <bits/stdc++.h>
using namespace std;
#define int long long
bool c(char x){
	if(x == 'D' || x == 'F') return 0;
	return 1;
}
bool l(char x, char y){
	if(x > y) swap(x, y);
	return (x == 'A' && y == 'B')
	     || (x == 'B' && y == 'C')
		 || (x == 'D' && y == 'F');
}
signed main(){
	 freopen("travel.in", "r", stdin);
	 freopen("travel.out", "w", stdout);
//int t = 5;
//while(t--){ 
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool ba =  c1 == c2;
	printf("%d", ba);
	bool bb = ba && (s1.substr(0, 2) == s2.substr(0, 2));
	printf("%d", bb);
	char n1 = s1[2];
	char n2 = s2[2];
	bool bc = bb && (c(n1) == c(n2));
	printf("%d", bc);
	printf("%d", bc && l(n1, n2));
//}
	return 0;
}
