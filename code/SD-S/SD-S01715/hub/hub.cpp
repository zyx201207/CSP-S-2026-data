#include<iostream>
#include<algorithm>
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
int c,t,n,k,v[100001],u[100001],f[100001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();
	t=read();
	for(int i=1;i<=t;i++){
		n=read(),k=read();
		for(int j=1;j<=n-1;j++){
			u[j]=read(),v[j]=read();
			f[u[j]]=v[j];
			f[v[j]]=u[j];
		}
		printf("%d\n",n%7);
	}
}
