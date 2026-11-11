#include<bits/stdc++.h>
using namespace std;
int n,c,m,d,q,k[505],dis[500005],w[500005];
vector<pair<int,int> >v[500005],e[500005];
struct Node{
	int v,w;
	bool operator <(Node const &o)const{return o.w<w;}
};
void dij(int s){
	priority_queue<Node>q;
	q.push({s,0});
	for(int i=1;i<=n;i++)dis[i]=2e9;
	dis[s]=0;
	while(!q.empty()){
		int now=q.top().v;
		q.pop();
		for(auto to:e[now]){
			if(dis[to.first]>dis[now]+to.second){
				dis[to.first]=dis[now]+to.second;
				q.push({to.first,dis[now]+to.second});
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,x,t;j<=k[i];j++){
			cin>>x>>t;
			v[x].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=m;i++){
		for(auto to:v[i]){
			for(auto to2:v[i]){
				if(to.first==to2.first)continue;
				e[to.first].push_back({to2.first,to.second+to2.second});
				e[to2.first].push_back({to.first,to.second+to2.second});
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=2e9,mi,ans2=2e9,mj;
		for(auto to:v[x]){
			if(to.second<ans)ans=to.second,mi=to.first;
		}
		for(auto to:v[y]){
			if(to.second<ans2)ans2=to.second,mj=to.first;
		}
		dij(mi);
		cout<<ans+ans2+w[x]+w[y]+dis[mj]<<endl;
	}
	return 0;
}

