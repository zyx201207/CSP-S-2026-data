#include<bits/stdc++.h>
using namespace std;
#define N 1007
#define ll long long
#define rnt register int
#define A first
#define B second
#define NOTAVAILABLE 0x3f3f3f3f
int c,T,n,k,a[N][N],dist[N][N],sum,sum1,maxd,ans,st[N];
bool tg[N];
void FloyD(){
	for(rnt i=1;i<=n;++i) for(rnt j=1;j<=n;++j) dist[i][j]=(a[i][j]==0?NOTAVAILABLE:a[i][j]);
	for(rnt i=1;i<=n;++i) for(rnt j=1;j<=n;++j) for(rnt k=1;k<=n;++k)
		dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}
void dfs(int x){
	tg[x]=1;
	for(rnt i=1;i<=n;++i){
		if(a[i][x]!=0&&st[a[i][x]]!=0&&!tg[a[i][x]]) dfs(a[i][x]);
		if(a[x][i]!=0&&st[a[x][i]]!=0&&!tg[a[x][i]]) dfs(a[x][i]);
	}
}
signed main(void){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;ans=NOTAVAILABLE;
		for(rnt i=1;i<=1000;++i) for(rnt j=1;j<=1000;++j) dist[i][j]=NOTAVAILABLE,a[i][j]=0;
		for(rnt i=1;i<=1000;++i) st[i]=tg[i]=0;
		for(rnt i=1;i<n;++i){
			int u,v;cin>>u>>v;
			a[u][v]=a[v][u]=1;
		}FloyD();
		while(!st[n+1]){
			maxd=sum=sum1=0;
			for(rnt i=1;i<=n;++i) sum+=st[i];
			for(rnt i=1;i<=n;++i) if(st[i]&&!tg[i]){
				dfs(i);++sum1;
			}
			if(sum==k&&sum1==2){
				for(rnt i=1;i<=n;++i) if(st[i]) for(rnt j=1;j<=n;++j) if(!st[j]&&dist[i][j]!=NOTAVAILABLE)
					maxd=max(maxd,max(dist[i][j],dist[j][i]));
				ans=min(maxd,ans);
			}++st[1];for(rnt i=1;i<=n;++i) if(st[i]>1)
				st[i]=0,st[i+1]++;
		}cout<<ans<<'\n';
	}
}
