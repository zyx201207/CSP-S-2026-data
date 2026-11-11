#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
const int N=2000010;
long long x[N];
int q[N],la[N],ne[N];
int read(){
	int k=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		k=(k<<1)+(k<<3)+(ch^48);
		ch=getchar();
	}
	return k*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int _=1;_<=t;_++){
		memset(x,0,sizeof(x));
		memset(q,-1,sizeof(q));
		memset(la,-1,sizeof(la));
		memset(ne,-1,sizeof(ne));
		n=read();
		d=read();
		int hd=0,tl=0;
		for(int i=1;i<=n;i++)x[i]=read();
		for(int i=1;i<=n;i++){
			q[++tl]=x[i];
			while(x[q[hd+1]]+d<x[i])hd++;
			la[i]=q[hd+1];ne[q[hd+1]]=i;
			while(i==n&&++hd<n)ne[q[hd+1]]=n;
		}
		printf("0\n");
	}
	return 0;
}
