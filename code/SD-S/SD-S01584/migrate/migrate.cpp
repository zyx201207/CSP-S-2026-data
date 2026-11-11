#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll x[N];
vector<int> e[N]; 
queue<int> Q;
int dis[N],sum[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		int n;
		ll ans=0,d;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;++i)scanf("%lld",&x[i]);
		if(c==11||c==12){
			ll s=d/(x[2]-x[1]);
			if(s>1)ans=max(0ll,n-2*s+1);
		}
		else{
			for(int i=1;i<=n;++i){
				while(e[i].size())e[i].pop_back();
				for(int j=i+1;j<=n;++j){
					if(x[j]-x[i]<=d)e[i].push_back(j);
				}
			}
			for(int i=1;i<=n;++i){
				while(Q.size())Q.pop();
				Q.push(i);
				dis[i]=0,sum[i]=1;
				for(int j=i+1;j<=n;++j)dis[j]=1e9,sum[j]=0; 
				while(Q.size()){
					int u=Q.front();
					Q.pop();
					for(int j=0;j<e[u].size();++j){
						int v=e[u][j];
						if(dis[v]>dis[u]+1){
							dis[v]=dis[u]+1;
							sum[v]=sum[u];
							Q.push(v);
						}
						else if(dis[v]==dis[u]+1)sum[v]=min(sum[v]+sum[u],3);
					}
				}
				for(int j=i;j<=n;++j)if(sum[j]==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
