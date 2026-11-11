#include<bits/stdc++.h>
using namespace std;
const int maxa=505,maxm=500005;
int n,m,d,q,w[maxm],a[maxa][maxa],t[maxa][maxa],dis[maxm],lnk[maxm],cnt,hep_size;
bool vis[maxa];
struct edge{
	int to,w,nxt;
}e[40000005]; 
struct AS{
	int x,id;
	bool operator<(const AS&B)const{return x<B.x;}
}hep[maxa];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
} 
void add_e(int x,int y,int z){e[++cnt]=(edge){y,z,lnk[x]};lnk[x]=cnt;}
void put(int x,int id){
	hep[++hep_size]=(AS){x,id};int son=1;
	while(son>1&&hep[son]<hep[son/2]) swap(hep[son],hep[son/2]),son/=2; 
}
AS get(){
	AS now=hep[1];int fa=1,son;hep[1]=hep[hep_size--];
	while(fa*2<=hep_size){
		if(fa*2+1>hep_size||hep[fa*2]<hep[fa*2+1]) son=fa*2;else son=fa*2+1;
		if(hep[son]<hep[fa]) swap(hep[fa],hep[son]),fa=son;else break;
	} 
	return now;
}
void DIJ(int s){
	memset(vis,0,sizeof vis);
	memset(dis,63,sizeof dis);
	put(0,s);dis[s]=0;
	while(hep_size){
		AS now=get();
		if(vis[now.id]) continue;
		vis[now.id]=1;
		for(int j=lnk[now.id];j;j=e[j].nxt){
			if(dis[e[j].to]<=e[j].w+dis[now.id]) continue;
			put(dis[e[j].to]=dis[now.id]+e[j].w,e[j].to); 
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int _=1;_<=n;_++){
		a[_][0]=read();
		for(int i=1;i<=a[_][0];i++) a[_][i]=read(),t[_][i]=read();
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i][0];j++)
			for(int k=j;k<=a[i][0];k++) add_e(a[i][j],a[i][k],t[i][j]+t[i][k]),add_e(a[i][k],a[i][j],t[i][j]+t[i][k]);	
	while(q--){
		int s=read(),t=read();
		DIJ(s);
		printf("%d\n",dis[t]+w[s]+w[t]);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
