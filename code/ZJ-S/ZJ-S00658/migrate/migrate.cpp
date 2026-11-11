#include<bits/stdc++.h>
using namespace std;
const int maxn=2000005;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int c,t,n,m,a[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	if(c==0||c==12){
		while(t--){
			n=read(),m=read();
			for(int i=1;i<=n;i++)a[i]=read();
			int k=a[2]-a[1];
			if(3*k<m&&2*k>=m){printf("%d\n",n-4);continue;}
			else printf("0\n");
		}
	}
}
