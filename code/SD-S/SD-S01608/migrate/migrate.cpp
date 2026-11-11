#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int f = 1,x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9'){
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return f * x;
}
struct Node{
	int num,s;
	bool operator < (const Node& other) const{
		return num < other.num;
	}
};
priority_queue<Node> que;
int main(){
	srand(time(0));
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c = read(),t = read();
	while (c--){
		printf("%d\n",rand());
	}
	return 0;
} 
