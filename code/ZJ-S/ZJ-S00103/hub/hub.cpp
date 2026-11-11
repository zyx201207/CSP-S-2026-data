#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+50;
ll c,t,n,k,fl[N],ans,cnt,dis[N],vis[N],dp[N][5],L[N][5],sz[N];
vector<ll>a[N];
void f(ll x,ll F,ll fa){
	for(auto u:a[x]){
		if(u==fa){
			continue;
		}
		if(F==0&&fl[u]==1)
		cnt++;
		f(u,fl[u],x);
	}
}
priority_queue<pair<ll,ll> >q;
void ch(ll x){
	cnt=0;
	ll y=x;
	while(x){
		cnt+=(x%2);
		x>>=1;
	}
	if(cnt>k)
	return;
	cnt=0;
	for(int i=1;i<=n;i++){
		fl[i]=(y>>(i-1))%2;
	}
	cnt=fl[1];
	f(1,fl[1],0);
	if(cnt>2)
	return;
	for(int i=1;i<=n;i++){
		dis[i]=1e9;
		vis[i]=0;
		if(fl[i]==1){
			dis[i]=0;
			q.push({0,i});
		}
	}
	ll sum=0;
	while(!q.empty()){
		ll s=q.top().second;
		q.pop();
		if(vis[s])
		continue;
		vis[s]=1;
		sum=max(sum,dis[s]);
		for(auto u:a[s]){
			if(dis[u]>dis[s]+1){
				dis[u]=dis[s]+1;
				q.push({-dis[u],u});
			}
		}
	}
	ans=min(ans,sum);
}
//void solve(ll x,ll fa){
//	ll mx=0,mx2=0;
//	for(auto u:a[x]){
//		if(u==fa)
//		continue;
//		solve(u,x);
//		for(int i=0;i<=1;i++){
//			dp[x][i]=max(dp[x][i],dp[u][i]);
//		}
//	}
//}
void get(ll x,ll fa){
	sz[x]=1;
	for(auto u:a[x]){
		if(u==fa)
		continue;
		get(u,x);
		sz[x]=max(sz[x],sz[u]+1);
	}
	return;
}
void solve2(){
	ll g=k-2;
	while(!q.empty()){
		ll t1=q.top().second;
		q.pop();
		if(fl[t1]==1)
		continue;
		if(g==0)
		break;
		g--;
		fl[t1]=1;
		for(auto u:a[t1]){
			if(fl[u]==1)
			continue;
			q.push({sz[u],u});
		}
	}
	ans=q.top().first;
	while(!q.empty()){
		q.pop();
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll u,v;
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%lld%lld",&u,&v);
			a[u].push_back(v);
			a[v].push_back(u);
		}
		ans=1e9;
		if(n==k){
			printf("0\n");
		}
		else if(n<=10){
			for(int i=1;i<(1<<n);i++){
				ch(i);
			}
			printf("%lld\n",ans);
		}
//		else if(k==2){
//			for(int i=1;i<=n;i++){
//				solve(i);
//			}
//			printf("%lld\n",ans);
//		}
		else{
//			ll K=10000;
			ll K=(1e4)/n+1;
			while(K){
//				cout<<K<<endl;
				K--;
				for(int i=1;i<=n;i++){
					fl[i]=sz[i]=0;
				}
				ll X=rand();
				X=(X*(c*2+1)+k)%n+1;
				fl[X]=1;
				ll Y=rand();
				Y=(Y*(c*2+1)+k)%n+1;
				fl[Y]=1;
				for(auto u:a[X]){
					if(u==Y)
					continue;
					get(u,X);
					q.push({sz[u],u});
				}
				for(auto u:a[Y]){
					if(u==X)
					continue;
					get(u,Y);
					q.push({sz[u],u});
				}
				solve2();
			}
			printf("%lld\n",ans);
		}
		for(int i=1;i<=n;i++){
			a[i].clear();
		}
	}
}
