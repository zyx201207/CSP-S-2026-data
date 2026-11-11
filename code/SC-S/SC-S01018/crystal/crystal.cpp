#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
const long long M = 1e18+5,A = 1e12+5;
long long read(){
	long long x = 0,f = 1;
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
void write(long long x){
	if(x>=10)write(x/10);
	char c;
	c = x%10 + '0';
	putchar(c);
}
long long n,m,arr[N],minn = A,maxx;
void init(){
	n = read(),m = read();
	for(int i = 1;i <= n;i++){
		arr[i] = read();
	}
	sort(arr+1,arr+n+1);
}
int L,R,mid;
bool check(int x){
	long long goat = arr[x];
	long long res = 0;
	for(int i = 1;i <= n;i++){
		res += (goat - arr[i]);
	}
//	printf("%d %d %d ret:%d\n",x,arr[x],res,res <= m);
	return res <= m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	init();
	L = 0,R = n;
	while(L<R){
		mid = (L+R+1)>>1;
		if(check(mid)){
			L = mid;
		}else{
			R = mid-1;
		}
	}
	write(L);
	return 0;
}


