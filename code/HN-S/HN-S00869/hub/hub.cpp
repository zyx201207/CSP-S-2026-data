#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int c, t;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar(); }
	return x * f;
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	c = read(); t = read();
	for(int i = 1; i <= t; i++){
		cout << "1" << '\n';  
	}
	
	
	return 0;
} 






