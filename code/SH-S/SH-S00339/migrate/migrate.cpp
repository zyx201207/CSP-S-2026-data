#include<bits/stdc++.h>
#define int long long
#define maxn 12345
#define maxN 2234567
using namespace std;
int c,t,n,d,D,x[maxN],ans,dis[maxn],cnt[maxn];
struct node{
	int u,w;
};
vector<int>G[maxn];
queue<node>pq;
void bfs(int s){
	pq.push({s,0});
	dis[s]=0;
	while(!pq.empty()){
		node X=pq.front();
		pq.pop();
		int _u=X.u,_w=X.w;
		for(int i=0;i<G[_u].size();i++){
			int v=G[_u][i];
			if(_w+1>dis[v])continue;
			else if(_w+1<dis[v]){
				pq.push((node){v,_w+1});
				dis[v]=_w+1;
				cnt[v]=1;
			}
			else{
				pq.push((node){v,_w+1});
				cnt[v]++;
			}
		}
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c<=10){
		while(t--){
			scanf("%lld%lld",&n,&d);
			ans=0;
			for(int i=1;i<=n;i++)G[i].clear();
			for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
			if(n==1){
				printf("0\n");
				continue;
			}
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)
					if(x[j]-x[i]<=d)G[i].push_back(j);
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)dis[j]=0x3f3f3f3f3f3f3f3f,cnt[j]=0;
				bfs(i);
				for(int j=1;j<=n;j++)
					if(cnt[j]==2)ans++;
			}
			printf("%lld\n",ans);
		}
	}
	else if(c==11||c==12){
		while(t--){
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
			if(n==1){
				printf("0\n");
				continue;
			}
			D=d/(x[2]-x[1]);
			if(D<=1){
				printf("0\n");
				continue;
			}
			printf("%lld\n",max(n-2*D+1,0ll));
		}
	}
	else{
		while(t--){
			scanf("%lld%lld",&n,&d);
			ans=0;
			for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
			if(n==1){
				printf("0\n");
				continue;
			}
			for(int i=1;i<=n;i++){
				if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
					D=i;
					break;
				}
			}
			if(D+2<=n&&D-1>=1&&x[D+2]-x[D-1]>d)ans++;
			if(D-2>=1&&D+1<=n&&x[D+1]-x[D-2]>d)ans++;
			printf("%lld\n",ans);
		}
	}
	return 0;
} 
