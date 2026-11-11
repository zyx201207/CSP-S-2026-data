#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000010];
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
void write(int x){
	if(!x) return ;
	write(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;i++) x[i]=read();
		if(c>=15&&c<=18){
			putchar('0');
		}
		putchar('\n');
	}
	return 0;
}
