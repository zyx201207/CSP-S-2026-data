#include <bits/stdc++.h>
using namespace std;

inline long long read(){
	long long x(0);
	int f(1);
	char c(getchar());
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
inline void write(long long x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	int c1, c2;
	string s("");
	string s1, s2;
	c1 = read();
	cin >> s1;
	c2 = read();
	cin >> s2;
	int p1 = (int)(s1[0] - '0') * 10 + (int)(s1[1] - '0');
	int p2 = (int)(s2[0] - '0') * 10 + (int)(s2[1] - '0');
	int y = (int)(s1[2] - 'A')+1;
	int z = (int)(s2[2] - 'A')+1;
	if(c1 == c2){
		if(p1 == p2){
			if((y >= 1 && y <= 3) && (z >= 1 && z <= 3)){
				if(y-z == 1 || z-y == 1){
					cout << "1111";
					return 0;
				}
				else{
					cout << "1110";
					return 0;
				}
			}
			if((y == 4 && z == 6) || (y == 6 && z == 4)){
				cout << "1111";
				return 0;
			}
			else{
				cout << "1100";
				return 0;
			}
		}
		else{
			cout << "1000";
			return 0;
		}
	}
	else{
		cout << "0000";
		return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
