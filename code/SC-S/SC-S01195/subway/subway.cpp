#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[5005],k,a[5005][5],t[5005][5],head[5005];
int len[1005][1005];
int read(){
	char s=getchar();
	int f=1,x=0;
	if(s=='-'){
		f=-1;
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		x=x*10+s-'0';
		s=getchar();
	}
	return x*f;
}
struct edge{
	int u,v,w;
	int next;
}e[50005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		k=read();
		for(int j=1;j<=2;j++){
			a[i][j]=read();
			t[i][j]=read();
		}
		len[a[i][1]][a[i][2]]=0;
		len[a[i][2]][a[i][1]]=0;
		e[i*2].u=a[i][1];
		e[i*2-1].v=a[i][1];
		e[i*2].u=a[i][2];
		e[i*2-1].v=a[i][2];
		e[i*2].w=0;
		e[i*2-1].w=0;
		e[i*2].next=head[a[i][1]];
		e[i*2-1].next=head[a[i][2]];
		head[a[i][1]]=i*2;
		head[a[i][2]]=i*2-1;
	}
	for(int i=1;i<=n;i++){
			
	}
}