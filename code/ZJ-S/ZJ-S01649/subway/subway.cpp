#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int M=125260,N=5e5+10;
int c,n,m,d,q,w[M],k[510],a[N],x,y,vis[M];
vector<pair<int,pair<int,int> > >v[M];
map<pair<int,int>,int>mp;
void bfs(){
	memset(vis,0,sizeof(vis));
	queue<pair<int,pair<long long,int> > >q;
	q.push({x,{0,0}});
	long long ans=1e17+10;
	while(!q.empty()){
		int aaa=q.front().first;
		long long bbb=q.front().second.first;
		int ccc=q.front().second.second;
		q.pop();
		if(aaa==y) {
			ans=min(ans,bbb);
			return ;
		}
		for(int i=0;i<v[aaa].size();++i){
			int fi=v[aaa][i].first;
			int se=v[aaa][i].second.first;
			int th=v[aaa][i].second.second;
			if(vis[fi]) continue;
			if(ccc!=0&&se!=ccc){
				q.push({fi,{bbb+th+mp[{fi,ccc}],se}});
				vis[fi]=1;
			}
		}
	}
	cout<<ans+w[x]+w[y]<<endl;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			int T;
			cin>>a[j]>>T;
			if(j>1){
				v[a[j]].push_back({a[j-1],{i,T}});
				v[a[j-1]].push_back({a[j],{i,T}});
			}
			mp[{a[j],i}]=T;
		}
	}
	while(q--){
		cin>>x>>y;
		bfs();
	}
	return 0;
}
/*
窗外的麻雀
在电线杆上多嘴
你说这一切
很有夏天的感觉
手中的铅笔
在纸上来来回回


秋刀鱼的滋味
她跟你都想了解 
*/ 
