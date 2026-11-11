#include<bits/stdc++.h>
using namespace std;
const long long maxn=6e5+7,inf=1e18+7;
long long tote,head[maxn],c,t,n,k,bo[maxn],ans,f[20][20],vis[maxn],dep[maxn],dis[1010][1010];
struct node{
	int to,nxt;
}e[maxn<<2];
void add(int u,int v){
	tote++;
	e[tote].to=v;
	e[tote].nxt=head[u];
	head[u]=tote;
	return ;
}
vector<int> vec;
void clr(int x,int fa){
	vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==fa||!bo[y]){
			continue;
		}
		clr(y,x);
	}
}
int check(){
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(bo[i]){
			if(!vis[i]){
				res++;
				clr(i,i);
			}
		}
	}
	if(res>2){
		return 0;
	}
	else{
		return 1;
	}
}
void dfs(int x,int tmp){
	if(x==n+1){
		if(tmp!=k){
			return ;
		}
		if(!check()){
			return ;
		}
		long long res=INT_MIN,tmp=inf;
		for(int i=1;i<=n;i++){
			tmp=inf;
			if(bo[i]){
				tmp=0;
			}
			for(auto j:vec){
				tmp=min(tmp,f[i][j]);
			}
			res=max(res,tmp);
		}
		ans=min(ans,res);
		return ;
	}
	vec.push_back(x);
	bo[x]=1;
	dfs(x+1,tmp+1);
	vec.pop_back();
	bo[x]=0;
	dfs(x+1,tmp);
	return ;
}
void clac(int x,int fa,int rt,int dep){
	dis[rt][x]=dep;
	dis[x][rt]=dep;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==fa){
			continue;
		}
		clac(y,x,rt,dep+1);
	}
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c<=3){
		while(t--){
			for(int i=1;i<=tote;i++){
				e[i]={0,0};
			}
			tote=0;
			for(int i=1;i<=n;i++){
				bo[i]=0;
				head[i]=0;
			}
			ans=inf;
			scanf("%lld%lld",&n,&k);
			for(int i=1;i<=n;i++){
				f[i][i]=0;
				for(int j=1;j<=n;j++){
					f[i][j]=inf;
				}
			}
			vec.clear();
			for(int i=1;i<n;i++){
				long long u,v;
				scanf("%lld%lld",&u,&v);
				add(u,v);
				add(v,u);
				f[u][v]=1;
				f[v][u]=1;
			}
			for(int K=1;K<=n;K++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						f[i][j]=min(f[i][j],f[i][K]+f[K][j]);
					}
				}
			}
			dfs(1,0);
			cout<<ans<<'\n';
		}
		return 0;
	}
	else if(c==7){
		while(t--){
			for(int i=1;i<=tote;i++){
				e[i]={0,0};
			}
			tote=0;
			for(int i=1;i<=n;i++){
				bo[i]=0;
				head[i]=0;
			}
			ans=inf;
			scanf("%lld%lld",&n,&k);
			vec.clear();
			for(int i=1;i<n;i++){
				long long u,v;
				scanf("%lld%lld",&u,&v);
				add(u,v);
				add(v,u);
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dep[j]=0;
				}
				clac(i,i,i,0);
			}
			for(int x=1;x<=n;x++){
				for(int y=x+1;y<=n;y++){
					long long res=INT_MIN,tmp=inf;
					for(int i=1;i<=n;i++){
						tmp=inf;
						if(i==x||i==y){
							tmp=0;
						}
						else{
							tmp=min({tmp,dis[x][i],dis[y][i]});
						}
						res=max(res,tmp);
					}
					ans=min(ans,res);
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17
*/
