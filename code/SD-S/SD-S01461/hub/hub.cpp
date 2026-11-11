#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+25;
const ll M=1e18;
ll read(){
	ll f=1,sum=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum*=10;
		sum+=(c-'0');
		c=getchar();
	}
	return sum*f;
}
ll c,t,n,dis[305][305],k,ANSWER_666=M;
bool vis[N],tag[N];
vector<ll> g[N];
void DFS(ll u){
	tag[u]=1;
	for(int i=0;i<g[u].size();i++){
		ll k=g[u][i];
		if(vis[k]==1&&tag[k]==0){
			DFS(k);
		}
	}
	return ;
}
void dfs(ll CNT){
	if(CNT==k){
		ll ans_cnt=0,ans_flag=0;
		for(int i=0;i<=n;i++)tag[i]=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1&&tag[i]==0){
				DFS(i);
				ans_cnt++;
			}
			if(ans_cnt>2){
				ans_flag=1;
				break;
			}
		}
		if(ans_flag)return ;
		ll ANS_D=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				ANS_D=max(ANS_D,(long long)0);
				continue;
			}
			ll Dist=M; 
			for(int j=1;j<=n;j++){
				if(vis[j]==0)continue;
				Dist=min(Dist,dis[i][j]);
			}
			ANS_D=max(ANS_D,Dist);
		}
		ANSWER_666=min(ANSWER_666,ANS_D);
		return ;	
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(CNT+1);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();
	t=read();
	while(t--){
		ANSWER_666=M;
		n=read();
		k=read();
		ll x=0,y=0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				dis[i][j]=M;
			}
		}
		for(int i=1;i<=n-1;i++){
			x=read();
			y=read();
			g[x].push_back(y);
			g[y].push_back(x);
			dis[x][y]=min(dis[x][y],(long long)1);
			dis[y][x]=min(dis[y][x],(long long)1);
		}		
		for(int v=1;v<=n;v++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][j],dis[i][v]+dis[v][j]);
				}
			}
		}
		dfs(0);
		printf("%lld\n",ANSWER_666);
		for(int i=1;i<=n;i++){
			g[i].clear();
			vis[i]=0;
		}
	}
	return 0;
} 
