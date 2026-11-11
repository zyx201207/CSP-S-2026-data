#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s = 0;
	int w = 1;
	char ch = getchar();
	while('0' > ch || '9' < ch){
		if(ch == '-') w *= -1;
		ch = getchar();
	}
	while('0' <= ch && '9' >= ch){
		s = (s << 1) + (s << 3) + (ch ^ 48);
		ch = getchar();
	}
	return w * s;
}//n 500 m 5e5 d 20  q  1e5
int c , n , m , d , q;
int w[500005] , k[500005] , a[505][500005] , t[505][500005] , x[100005] , y[100005];
void init(){
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for(int i = 1;i <= m;i++) w[i] = read();
	for(int i = 1;i <= n;i++){
		k[i] = read();
		for(int j = 1;j <= k[i];j++){
			a[i][j] = read();
			t[i][j] = read();
		}
	}
	for(int r = 1;r <= q;r++){
		x[r] = read();
		y[r] = read(); 
	}
}
//×î¶ÌÂ· 
int main(){
	init();
} 
