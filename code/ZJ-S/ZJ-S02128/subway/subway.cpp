#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool flag=1;
long long sum=0,n,c,m,d,q,w[500005],k[505],a[505][5005],t[505][5005],x,y;
long long read(){
	long long nov=1,dat=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') nov=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		dat=(dat<<3)+(dat<<1)+(c&15);
		c=getchar();
	}
	return nov*dat;
}
//int dfs(long long x,long long y){
//	return 0;
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		if(k[i]>2) flag=0;
		for(int j=1;j<=k[i];j++){
			a[i][j]=read(),t[i][j]=read();
		}
	}
	for(int i=1;i<=q;i++){
		x=read(),y=read();
		sum=w[x];
		if(flag==1){
			//dfs(x,y);
		}
	}
	return 0;
}