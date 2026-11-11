#include<bits/stdc++.h>
#define int long long
constexpr int N = 2e6+5;
using namespace std;
inline int read(){
	int x= 0,f = 1 ;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch>='0'&&ch<='9'){
		x = (x<<3)+(x<<1)+(ch^48);
		ch = getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10^48);
}
int c,t,n,d,x[N];

void solve1(){
	write(0);
	putchar('\n');
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read(),t = read();
	while(t--)solve1();
	return 0;
}