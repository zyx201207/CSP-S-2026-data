#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,M=5e3+5;
#define ll long long
ll qrd(){
	char c;ll ret=0;
	int sign=1;
	do{
		c=getchar();
		if(c=='-')sign=-1;
	}while(!isdigit(c));
	do{
		ret=ret*10+c-'0';
		c=getchar();
	}while(isdigit(c));
	return ret*sign;
}
int c,T,n,k;
bool edge[20][20];
int dis[20][20];
bool iskey(int u,int p){
	return (p>>(u-1))&1;
}
int dfs(int u,int f,int p){
	int ret=0;
	if(iskey(u,p)&&!iskey(f,p))ret++;
	for(int v=1;v<=n;v++){
		if(v==f)continue;
		if(edge[u][v])ret+=dfs(v,u,p);
	}
	return ret;
}
void solve1(){
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<n;i++){
		int u,v;u=qrd();v=qrd();
		edge[u][v]=edge[v][u]=1; 
		dis[u][v]=dis[v][u]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int ans=10000; 
	for(int p=0;p<(1<<n);p++){
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++)if(iskey(i,p))cnt1++;
		if(cnt1!=k)continue;
		cnt2=dfs(1,0,p);
		if(cnt2>2)continue;
		int tmp=0;
		for(int i=1;i<=n;i++){
			if(iskey(i,p))continue;
			int sum=10000;
			for(int j=1;j<=n;j++)
				if(iskey(j,p))sum=min(sum,dis[i][j]);
			tmp=max(tmp,sum);
		}
		ans=min(ans,tmp);
	}
	printf("%d\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=qrd();T=qrd();
	while(T--){
		n=qrd();k=qrd();
		if(c<=3)solve1();
		memset(edge,0,sizeof edge);
	}
	return 0;
}