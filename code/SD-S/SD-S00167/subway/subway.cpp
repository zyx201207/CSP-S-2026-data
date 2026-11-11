#include<bits/stdc++.h>
#define int long long
#define pii pair<long long,long long>
using namespace std;
const int N=5e5+5;
map<int,int> vis,dis;
vector< pair<int,int> > sta[N];
vector<int> way[N];
priority_queue< pii,vector<pii>,greater<pii> > pq;
int c,n,m,d,q;
int w[N],K,A,T;
int s,t;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",w+i);
	for(int i=1;i<=n;i++){
		scanf("%lld",&K);
		for(int j=1;j<=K;j++){
			scanf("%lld %lld",&A,&T);
			way[i].push_back(A);
			sta[A].push_back({i,T});
		}
	}
	while(q--){
		scanf("%lld %lld",&s,&t);
		for(auto i:sta[s]){
			pq.push({i.second+w[s],(i.first-1)*m+s});
			vis[(i.first-1)*m+s]=1;
			dis[(i.first-1)*m+s]=i.second+w[s];
		}
		while(!pq.empty()){
			auto top=pq.top();
			pq.pop();
			int d=top.first,s=top.second;
			if(vis[s])continue;
			vis[s]=1;
			bool flag=0;
			for(auto i:way[s/m+1]){
				if(i==s%m)flag=1;
				if(flag)continue;
				if(vis[s/m*m+i])continue;
				dis[s/m*m+i]=d;
				pq.push({d,s/m*m+i});
			}
			int W=0;
			for(auto i:sta[s%m])
				if(i.first==s/m+1)W=i.second;
			for(auto i:sta[s%m]){
				if(vis[(i.first-1)*m+s%m])continue;
				dis[(i.first-1)*m+s%m]=W+d+i.second;
				pq.push({dis[(i.first-1)*m+s%m],(i.first-1)*m+s%m});
			}
		}
		int ans=1e18;
		for(auto i:sta[t]){
			if(dis[t+(i.first-1)*m])ans=min(ans,dis[t+(i.first-1)*m]+i.second);
		}
		printf("%lld\n",ans+w[t]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
