#include<cstdio>
#define int long long
#define MAXN 2000100
bool stfff;
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
inline int max(int a,int b){return a<b?b:a;}
int c,T;
int n,d;
int a[MAXN];
bool steee;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();T=read();
	if(c==11||c==12){
		while(T--){
			n=read();d=read();
			for(int i=1;i<=n;i++)a[i]=read();
			if(n==1){
				putchar('0');putchar('\n');
				continue;
			}
			int del=a[2]-a[1];
			int p=d/del;
			if(p<=1){
				putchar('0');putchar('\n');
				continue;
			}
			int dis=2*p;
			int ans=(n-dis+1);
			write(max(ans,0));
			putchar('\n');
		}
	}
	else{
		while(T--){
			n=read();d=read();
			for(int i=1;i<=n;i++)a[i]=read();
			int sum=0;
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					if(a[j]-a[i]<=d)continue;
					int cnt=0;
					for(int k=i+1;k<=j-1;k++){
						if(a[k]-a[i]<=d and a[j]-a[k]<=d){
							cnt+=1;
						}
					}
					if(cnt==2){
						int p;
						for(p=i-1;p>=1;p--){
							int o=0;
							if(a[p+1]-a[p]<=d&&(p==1||a[p+1]-a[p-1]>d))o=1;
							else break;
						}
						int le=i-p;
						int rt;
						for(rt=j+1;rt<=n;rt++){
							int o=0;
							if(a[rt]-a[rt-1]<=d&&(rt==n||a[rt+1]-a[rt-1]>d))o=1;
							else break;
						}
						int re=rt-j;
						sum+=le*re;
					}
				}
			}
			write(sum);
			putchar('\n');
		}
	}
	return 0;
}/*

5 3
-3 0 2 3 4
2

*/