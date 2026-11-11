#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
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
int head[N],edge_len=1;
struct Edge{
	int to,next;
}edge[N];
void add(int u,int v){
	edge[edge_len].to = v;
	edge[edge_len].next = head[u];
	head[u] = edge_len++;
}
int c,t,n,k;
void init(){
//	memset(edge,0,sizeof(edge));
	n = read(),k = read();
	for(int i = 1;i <= n;i++){
		int u = read(),v = read();
//		add(u,v),add(v,u);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c = read(),t = read();
	while(t--){
		init();
		printf("%d\n",((n+1)/2 -(k+1)/2)/2);
	}
	return 0;
}