#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+7;
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
ll c,t,n,d,a[N],dis[N],b[N],cnt=0;
bool vis[N];
vector<ll> g[N];
priority_queue<pair<ll,ll> > Q;
void dij(ll st){
	for(int i=0;i<=n;i++){
		dis[i]=M;
		vis[i]=0;
		b[i]=0;
	}
	dis[st]=0;
	vis[st]=1;
	b[st]=1;
	Q.push(make_pair(0,st));
	while(Q.size()){
		ll u=Q.top().second;
		vis[u]=0;
		Q.pop();
		for(int i=0;i<g[u].size();i++){
			ll v=g[u][i];
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				b[v]=b[u];
				if(!vis[v]){
					vis[v]=1;
					Q.push(make_pair(-dis[v],v));
				} 
			}
			else if(dis[v]==dis[u]+1){
				b[v]+=b[u];
				if(!vis[v]){
					vis[v]=1;
					Q.push(make_pair(-dis[v],v));
				} 
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i==st)continue;
		if(b[i]==2)cnt++;
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--){
		n=read();
		d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
				else{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			dij(i);
		}
		printf("%lld\n",cnt/2);
		for(int i=1;i<=n;i++){
			a[i]=0;
			g[i].clear();
		} 
		cnt=0;
	}
	return 0;
} 
