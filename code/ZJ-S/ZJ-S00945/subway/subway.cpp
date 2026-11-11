#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxe=1250005;
LL n,m,d,q,lnk[maxe],f[maxe],que[maxe],cnt,cnt2;
bool vis[maxe];
struct edge{
	int to,nxt,w;
}e[maxe];
int read(){
	int num=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))num=num*10+ch-'0',ch=getchar();
	return num*f;
}
void add_e(int x,int y,int z){e[++cnt]=(edge){y,lnk[x],z};lnk[x]=cnt;}
LL spfa(int st,int en){
	memset(f,63,sizeof f);
	memset(vis,0,sizeof vis);
	int hed=0,til=1,maxp=12500000;
	vis[st]=1,que[1]=st,f[st]=0;
	while(hed!=til){
		hed=(hed+1)%maxp;
		int x=que[hed];
		vis[x]=0;
		for(int j=lnk[x];j;j=e[j].nxt){
			if(f[x]+e[j].w>=f[e[j].to])continue;
			f[e[j].to]=f[x]+e[j].w;
			if(!vis[e[j].to])til=(til+1)%maxp,vis[e[j].to]=1,que[til]=e[j].to;
		}
	}
	return f[en];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(),n=read(),m=read(),d=read(),q=read();
	cnt2=2*m;
	for(int i=1;i<=m;i++){
		int x=read();
		add_e(i,i+m,x),add_e(i+m,i,x);
	}
	for(int i=1;i<=n;i++){
		int k=read(),x,y,xx;
		for(int j=1;j<=k;j++){
			x=read(),y=read();
			++cnt2;
			if(j>1)add_e(xx,cnt2,0),add_e(cnt2,xx,0);
			xx=cnt2;
			add_e(x+m,cnt2,y),add_e(cnt2,x+m,y);
		}
	}
	while(q--)cout<<spfa(read(),read())<<"\n";
	return 0;
}