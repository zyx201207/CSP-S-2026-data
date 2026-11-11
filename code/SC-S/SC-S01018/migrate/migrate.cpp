#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int read(){
	int x = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-'){
			f *= -1;
		}
		c = getchar();
	}
	while('0' <= c && c <= '9'){
		x = (x<<1)+(x<<3)+(c-'0');
		c = getchar();
	}
	return x*f;
}
char get_char(){
	char c = getchar();
	while((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))c = getchar();
	return c;
}
void write(int x){
	if(x>=10)write(x/10);
	char c;
	c = x%10 + '0';
	putchar(c);
}
long long d,island[N];
int c,t,n;
long long minn = 1e18+5,maxx;
void init(){
	n = read(),d = read();
	memset(island,0,sizeof(island));
	for(int i = 1;i <= n;i++){
		island[i] = read();
		minn = min(minn,island[i]);
		maxx = max(maxx,island[i]);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read(),t = read();
	while(t--){
		init();
		printf("%d\n",(maxx-minn)/d);
	}
	return 0;
}

