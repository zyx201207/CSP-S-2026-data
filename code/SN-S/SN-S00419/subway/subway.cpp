#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> PI;
ll c,n,m,d,qn,w[500010],xr,yr,ans=0,dis[1000010];
struct Rode{
	ll v;
	ll t;
};
vector<Rode>a[1000010];
priority_queue<PI,vector<PI>,greater<PI> >q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qn;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll wei,time;
			cin>>wei>>time;
			a[wei].push_back({i+m,time});
			a[i+m].push_back({wei,time});
		}
	}
	while(qn--){
		for(int i=1;i<=n+m;i++)dis[i]=1e9;
		ans=0;
		cin>>xr>>yr;
		ans=ans+w[xr]+w[yr];
	
		q.push({xr,0});
		while(!q.empty()){
			PI now=q.top();
			q.pop();
			ll u=now.first;
			if(dis[u]<now.second)continue;
			for(auto i:a[u]){
				if(now.second+i.t<dis[i.v]){
					dis[i.v]=now.second+i.t;
					q.push({i.v,dis[i.v]});
				}
			}
		}
		ans+=dis[yr];
		cout<<ans<<endl;
	}
	return 0;
}
