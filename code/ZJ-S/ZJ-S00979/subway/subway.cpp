#include<bits/stdc++.h>
using namespace std;
const int maxe=30000000,maxn=505,maxk=500005;
int n,m,Q,c,d,son[maxe],lnk[maxe],nxt[maxe],w[maxe],tot,num,gid[maxe],len;
long long dis[maxe],f[maxn][maxn],W[maxk];
struct CC{
	long long x,id;
}g[maxe];
void add(int x,int y,int z){
	nxt[++tot]=lnk[x],lnk[x]=tot,son[tot]=y,w[tot]=z;
}
void swap_(int a,int b){
	swap(g[a].x,g[b].x);
	swap(g[a].id,g[b].id);
}
void put(long long x,int id){
	g[++len]=(CC){x,id},gid[g[len].id]=len;int now=len;
	while(now/2>=1){
		if(g[now/2].x>g[now].x){
			swap(gid[g[now].id],gid[g[now/2].id]),
			swap_(now/2,now);
			now/=2;
		}else{
			break;
		}
	}
}
void up(int now){
	while(now*2<=len){
		int u=0;
		if(now*2+1<=len&&g[now*2].x>g[now*2+1].x){
			u=1,now=now*2+1;swap(gid[g[now*2+1].id],gid[g[now].id]),swap_(now*2+1,now);
		}
		if(now*2+1>len||g[now*2].x<g[now*2+1].x){
			u=1,now=now*2;swap(gid[g[now*2].id],gid[g[now].id]),swap_(now*2,now);
		}
		if(u==0) break;
	}
}
CC get(){
	CC res=g[1];int now=1;swap_(len,1);gid[len]=0,len--;
	up(now);
	return res;
}
void DIJ(int S){
	memset(dis,63,sizeof dis);
	dis[S]=0;
	put(dis[S],S);
	while(len>=1){
		CC now=get();
		for(int j=lnk[now.id];j;j=nxt[j]){
			if(dis[now.id]+w[j]<dis[son[j]]){
				dis[son[j]]=dis[now.id]+w[j];
				put(dis[son[j]],son[j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,127,sizeof f);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	num=2*m;
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d",&x);
		W[i]=x;
		add(i,i+m,x),add(i+m,i,x);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int y,z;
			scanf("%d%d",&y,&z);
			num++;
			if(j!=1) add(num-1,num,0),add(num,num-1,0);
			add(num,y+m,z),add(y+m,num,z);
		}
	}
	for(int i=1;i<=m;i++){
		DIJ(i+m);
		for(int j=1;j<=m;j++){
			f[i][j]=dis[j+m];
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(Q--){
		int L,R;
		scanf("%d%d",&L,&R);
		printf("%lld\n",f[L][R]+W[L]+W[R]);
	}
	return 0;
}