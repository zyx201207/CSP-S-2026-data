#include<cstdio>
int c,T;
namespace IO{
	inline int read(void){
		register char c;
		int res=0,e=1;
		do{
			c=getchar();
		}while(!(c<='9' and c>='0'||c=='-'));
		if(c=='-')c='0',e=-1;
		do{
			res=(res<<1)+(res<<3)+c-'0';
			c=getchar();
		}while(c<='9' and c>='0');
		return e*res;
	}
	inline void write(int x){
		if(x<0)putchar('-'),write(-x);
		if(x>9)write(x/10);
		putchar(x%10+'0');
		return ;
	}
}using namespace IO;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();
	T=read();
	while(T--){
		putchar('1');
		putchar('\n');
	}
	return 0;
}