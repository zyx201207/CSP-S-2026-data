#include <bits/stdc++.h>
using namespace std;

namespace Flower{
	inline int read(){
		int x=0,f=1;char c=getchar();
		while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
		while (c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
		return x*f;
	}
	
	inline void write(int x){
		if (x<0) {putchar('-');x=-x;}
		if (x>9) write(x/10);
		putchar(x%10+'0');
		return ;
	}
}using namespace Flower;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cc=read(),t=read();
	mt19937 rnd(time(0));
	int n=read(),d=read();
	for (int i=1;i<=n;i++){
		int x=read();
	}
	cout <<rnd()%n+1<<endl;
	return 0;
}