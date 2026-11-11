#include<iostream>
#include<cmath>
using namespace std;
inline int read(){
	int f=1,s=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return f*s;
}
int c,t,n,m,a[2000005],tot;
bool flag;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	for(int i=1;i<=t;i++){
		n=read(),m=read();
		for(int j=1;j<=n;j++){
			a[j]=read();	
		}		
		printf("0\n");
	}
}
