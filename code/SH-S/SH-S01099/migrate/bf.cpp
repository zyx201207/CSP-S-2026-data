#include<bits/stdc++.h>
#define N ((int)(2e6)+10)
using namespace std;
using ll=long long;
struct info{int u;ll dd;};
int c,T,n;
ll d,x[N];
vector<int> G[N];
int cnt[N];
ll dis[N];
void bfs(int st){
	queue<info> Q;
	fill(cnt+1,cnt+n+1,0);
	fill(dis+1,dis+n+1,(ll)3e18);
	Q.push({st,0ll}),dis[st]=0;
	while(!Q.empty()){
		auto now=Q.front();Q.pop();
		int u=now.u;ll dd=now.dd;
		if(dd>dis[u]||cnt[u]>2)continue;
		cnt[u]++,dis[u]=dd;
		for(int v:G[u]){
			if(cnt[v]<=2&&dis[v]>=dd+1)Q.push({v,dd+1});
		}
	}
}
signed main(){
	freopen("migrate6.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++){
			int l=lower_bound(x+1,x+n+1,x[i]-d)-x;
			int r=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
			for(int j=l;j<=l+2;j++)
				if(j<i)G[i].push_back(j);
			for(int j=r;j>=r-2;j--)
				if(j>i)G[i].push_back(j);
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=1;j<=n;j++)ans+=(cnt[j]==2);
			if(!(i%1000))cout<<i<<endl;
		}
		printf("%lld\n",ans/2);
	}
}
