#include<cstdio>
using namespace std;
inline long long readin(){
	long long num=0;
	char ch=' ';
	long long sgn=1;
	while(ch==' '||ch=='\n'||ch=='\r')ch=getc(stdin);
	if(ch!=EOF)if(ch=='-')sgn=-1,ch=getc(stdin);
	while('0'<=ch&&ch<='9'&&ch!=EOF){
		num=((num<<1)+(num<<3))+((long long)ch-'0');
		ch=getc(stdin);
	}
	return num*sgn;
}
int fd[2000010],bk[2000010];
int T;
long long X[2000010];
int C,N;
long long D;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=readin(),T=readin();
	if(11<=C&&C<=12||true){
		while(T--){
			N=readin(),D=readin();
			for(int i=1;i<=N;i++)X[i]=readin();
			
			if(N>2){
				long long delta=X[2]-X[1];
				long long maxl=D/delta;
				if(D<2*delta){
					puts("0");
					continue;
				}
				long long ans=(long long)(N-(2*(__int128)maxl-1));
				printf("%lld\n",ans>0?ans:0);
			}else{
				puts("0");
			}
		}
	}
	return 0;
}
//!??!
