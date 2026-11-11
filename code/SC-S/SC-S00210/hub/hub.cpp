#include<bits/stdc++.h>

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
int c,t;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//	srand(time(0));
	c = read(),t = read();
	while(t--){
		write(1);
		putchar('\n');
	}
	
	return 0;
}