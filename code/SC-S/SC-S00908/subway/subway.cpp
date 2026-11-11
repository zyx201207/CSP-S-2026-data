#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxm=5e5+10,maxq=1e5+10;
vector<pair<ll,int>> e[maxm];
vector<int> ask[maxm];
struct edge{
	int u,v;
}qu[maxq];
int c,n,m,d,q;
ll w[maxm],k[maxm],t[maxm],a[maxm],dis[maxm],ans[maxq];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>qp;
void dj(int u){
	memset(dis,127,(m+5)*sizeof(long long));
	dis[u]=0;
	qp.push({0,u});
	while(!qp.empty()){
		auto v=qp.top();
		qp.pop();
		if(v.first>dis[v.second])continue;
		for(const auto &a:e[v.second]){
			ll temp=a.first+dis[v.second];
			//cout<<temp<<" "<<dis[a.second]<<"\n";
			if(temp<dis[a.second]){
				//cout<<1<<"\n";
				qp.push({temp,a.second});
				dis[a.second]=temp;
			}
		}
	}
}
void read(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int l=1;l<=n;l++){
		cin>>k[l];
		for(int i=1;i<=k[l];i++){
			cin>>a[i]>>t[i];
			//cout<<a[i]<<" "<<t[i]<<"\n";
			for(int j=1;j<i;j++){
				ll temp=t[i]+t[j];
				//cout<<a[i]<<" "<<a[j]<<"\n";
				e[a[i]].push_back({temp,a[j]});
				e[a[j]].push_back({temp,a[i]});
			}
		}
	}
	int maa=0;
	for(int i=1;i<=q;i++){
		cin>>qu[i].u>>qu[i].v;
		maa=max(maa,qu[i].u);
		ask[qu[i].u].push_back(i);
	}
	for(int i=1;i<=maa;i++){
		if(ask[i].empty())continue;
		dj(i);
		for(const auto &a:ask[i]){
			ans[a]=dis[qu[a].v]+w[qu[a].u]+w[qu[a].v];
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	read();
	
	return 0;
}