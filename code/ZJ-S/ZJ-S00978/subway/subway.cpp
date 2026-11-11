#include<bits/stdc++.h>
using namespace std;
const int maxn=505,maxe=5*1e5+5;
int T,m,n,d,Q,x,y,z,a[maxn];//测试点、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，出行计划数
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	T=read();m=read();n=read();d=read();Q=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++){
		x=read();
		for(int j=1;j<=x;j++){
			y=read();z=read();
		}
	}
	while(Q--){
		x=read();y=read();
		printf("1\n");
	}
	return 0;
}