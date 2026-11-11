#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

ll c,t;
ll n,d;
ll x[2000005];

ll dist[2000005],f[2000005],cnt[2000005];
priority_queue<pii,vector<pii>,greater<pii>> que;

void dijkstra(ll st){
	memset(dist,0x3f,sizeof dist);
	memset(f,0,sizeof f);
	memset(cnt,0,sizeof cnt);
	dist[st]=0;
	cnt[st]=1;
	que.push({0,st});
	while(!que.empty()){
		pii it=que.top();que.pop();
		int u=it.second,w=it.first;
		if(f[u])continue;
		for(int v=1;v<=n;v++){
			if(abs(x[v]-x[u])>d||v==u)continue;
			if(dist[v]>dist[u]+1){
				cnt[v]=1;
				dist[v]=dist[u]+1;
				que.push({dist[v],v});
			}
			else if(dist[v]==dist[u]+1)cnt[v]++;
		}
	}
}

void work(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++)cin>>x[i];
	ll ans=0;
	for(ll i=1;i<=n;i++){
		dijkstra(i);
		for(ll i=1;i<=n;i++){
//			cout<<cnt[i]<<' ';
			if(cnt[i]==2)ans++;
		}
//		cout<<'\n';
	}
	cout<<((ans&1)?ans/2+1:ans/2)<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)work();
	return 0;
}