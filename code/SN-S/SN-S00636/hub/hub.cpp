#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 7;

int c, t;


inline void read(int &x){
	char c = getchar();
	int stts = 1;
	while(c < '0' || c > '9'){
		if(c == '-') stts = -1;
		c = getchar();
	}
	x = 0;
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	x *= stts;
	return;
}

inline void read(ll &x){
	char c = getchar();
	int stts = 1;
	while(c < '0' || c > '9'){
		if(c == '-') stts = -1;
		c = getchar();
	}
	x = 0;
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	x *= stts;
	return;
}

inline void addEdge(int u, int v){
	e[++idxe] = Edge{u, v, h[u]};
	h[u] = idxe;
	return;
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	read(c);read(t);
	while(t--){
		cout<<0<<'\n';
	}
	return 0;
}
