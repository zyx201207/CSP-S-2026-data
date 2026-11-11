#include<bits/stdc++.h>
#define maxm 400005
#define maxn 505
using namespace std;
int c,n,m,d,Q;
int tal,hed;
int w[maxm];        /*从地铁口到站厅*/
struct s{
	int name,time;
}station[maxm][25];
int dis[maxm];
struct plan{
	int id,spend;
}q[5000001];
struct xian{
	int k,sta[maxm],t[maxm];
}a[505];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int BFS(int x,int y){
	memset(dis,63,sizeof dis);
	hed=tal=0;
	q[++tal]=(plan){x,w[x]};
	dis[x]=w[x];
	while(hed<=tal){
		hed++;
		plan CNT=q[hed];
		plan cnt=q[hed];
		for(int i=1;i<=station[cnt.id][0].name;i++){
		if(hed==1) cnt.spend=CNT.spend+station[x][i].time;
		for(int j=1;j<=a[station[cnt.id][i].name].k;j++){	
		if(dis[a[station[cnt.id][i].name].sta[j]]>cnt.spend+a[station[cnt.id][i].name].t[j]){
		q[++tal]=(plan){a[station[cnt.id][i].name].sta[j],cnt.spend+a[station[cnt.id][i].name].t[j]};
		dis[a[station[cnt.id][i].name].sta[j]]=cnt.spend+a[station[cnt.id][i].name].t[j];
		}
	}
}
}
	return dis[y]+w[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),Q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		a[i].k=read();
		for(int j=1;j<=a[i].k;j++){
			a[i].sta[j]=read(),a[i].t[j]=read();
			station[a[i].sta[j]][++station[a[i].sta[j]][0].name]=(s){i,a[i].t[j]};
		}
	}
	while(Q--){
		int x=read(),y=read();
		printf("%d\n",BFS(x,y));
	}
	return 0;
}