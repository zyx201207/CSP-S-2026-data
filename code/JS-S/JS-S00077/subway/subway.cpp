#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct NODE{
	int v,t;
};
struct NODE1{
	int u,v;
	ll t;
	friend bool operator<(NODE1 a,NODE1 b){return a.t>b.t;}
};
int c,n,m,d,q;
ll ans;
vector<int>dtk;
vector<vector<NODE>>dt;
vector<ll>zdsj;
priority_queue<NODE1>pq;
void zdl(int now,int pre,int end,ll ti){
	zdsj[now]=ti;
	if(now==end){
		while(!pq.empty()) pq.pop();
		return ;
	}
	for(auto x:dt[now]){
		if(x.v!=pre) pq.push({now,x.v,ti+x.t});
	}
	while(!pq.empty()){
		NODE1 ls=pq.top();
		pq.pop();
		zdl(ls.v,ls.u,end,ls.t);
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	dtk.assign(m+1,0);
	dt.assign(m+n+1,vector<NODE>());
	for(int i=1;i<=m;i++) cin>>dtk[i];
	for(int i=1,s;i<=n;i++){
		cin>>s;
		for(int j=1,sta,t;j<=s;j++){
			cin>>sta>>t;
			dt[sta].push_back({i+m,t});
			dt[i+m].push_back({sta,t});
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		ans=dtk[s]+dtk[e];
		zdsj.assign(n+m+1,0);
		zdl(s,0,e,0ll);
		ans+=zdsj[e];
		cout<<ans<<"\n";
	}
	return 0;
}
