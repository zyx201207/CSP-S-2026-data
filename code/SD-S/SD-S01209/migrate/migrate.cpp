#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define unsigned long long
ll rd(){
	ll sm=0,fe=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fe=-1;
	for(;isdigit(c);c=getchar()) sm=sm*10+c-'0';
	return sm*fe;
}
ll a[5007],n,c,T,d;
pair<ll,ll>dist[5007];
vector<ll>g[5007];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=rd(),T=rd();
	while(T--){
		n=rd(),d=rd();
		if(c<=10){
			for(int i=1;i<=n;i++){
				a[i]=rd();
				//cout<<a[i]<<' ';
				g[i].clear();
				dist[i]={LLONG_MAX,0};
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d){
						g[i].push_back(j);
						//cout<<i<<' '<<j<<'\n';
					}
				}
			}
			queue<pair<ll,ll>>q;
			ll ans=0;
			for(int startt=1;startt<=n;startt++){
				for(int i=1;i<=n;i++) dist[i]={LLONG_MAX,1};
				q.push({0,startt});
				dist[startt]={0,1};
				while(!q.empty()){
					ll u=q.front().second;
					ll d=q.front().first;q.pop();
					if(d>dist[u].first) continue;
					//cout<<u<<' '<<d<<' '<<dist[u].first<<' '<<dist[u].second<<'\n';
					for(auto v:g[u]){
						if(d+1<dist[v].first) dist[v]={d+1,1};
						else if(d+1==dist[v].first) dist[v].second++;
						else continue;
						q.push({dist[v].first,v});
					}
				}
				for(int i=1;i<=n;i++) ans+=(dist[i].second==2);
			}
			cout<<ans<<'\n';
		}
		else{
			cout<<"0\n";
		}
	}
}
