#include<bits/stdc++.h>
using namespace std;
unsigned long long f[501][501];
int w[500010];
int c,n,m,d,q,s,t,co,xr,yr;
int to[500010],cost[500010],head[500010],nxt[500010];
int cnt=0;
vector<pair<int,int> >lis[501];
void add_edge(int x,int y,int z){
	cnt++;
	to[cnt]=y; cost[cnt]=z; nxt[cnt]=head[x]; head[x]=cnt;
	return;
}
void pre(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(f[i][k]==LLONG_MAX)continue;
			for(int j=1;j<=n;j++){
				if(f[k][j]!=LLONG_MAX)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)f[i][j]=0;
			else f[i][j]=LLONG_MAX;
		}
	}
	unsigned long long u;
	for(int i=1;i<=n;i++){
		scanf("%d",&s);
		for(int j=1;j<=s;j++){
			scanf("%d%d",&t,&co);
			for(int k=head[t];k!=0;k=nxt[k]){
				u=min(f[i][to[k]],(unsigned long long)co+(unsigned long long)cost[k]);
				f[to[k]][i]=u;f[i][to[k]]=u;
			}
			add_edge(t,i,co);			
		}
	}
	pre();
	unsigned long long ans;
	for(int i=1;i<=q;i++){
		scanf("%d%d",&xr,&yr);
		ans=LLONG_MAX;
		for(int j=head[xr];j!=0;j=nxt[j]){
			for(int k=head[yr];k!=0;k=nxt[k]){
				ans=min(ans,f[to[j]][to[k]]+w[xr]+w[yr]+cost[j]+cost[k]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}