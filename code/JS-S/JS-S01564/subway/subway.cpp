#include<bits/stdc++.h>
using namespace std;
#define ll int
int n,m;
vector<vector<ll> >ds;
vector<vector<ll> >dm;
vector<vector<pair<int,int> > >mp;
vector<vector<pair<int,int> > >sub;
ll dijkstra(int st,int en){
	for(int i=0;i<=n;i++)ds[st][i]=(1<<30);
	for(int i=0;i<=m;i++)dm[st][i]=(1<<30);
	priority_queue<pair<ll,int>,vector<pair<ll,int> > ,greater<pair<ll,int> > >q;
	//q.push({1LL*1<<60,100000});
	//q.push({1LL*1<<60,100000});
	q.push({0,st});
	while(!q.empty()){
		pair<ll,int>f=q.top();
		
		q.pop();
		if(f.second==en){
			
			//cout<<"f={"<<f.first<<','<<f.second<<'}'<<endl;
			return f.first;
		}
		
		if(dm[st][f.second]<=f.first)continue;
		//cout<<"f={"<<f.first<<','<<f.second<<'}'<<endl;
		dm[st][f.second]=f.first;
		for(int i=0;i<mp[f.second].size();i++){
	
			f.first+=mp[f.second][i].second;
			if(ds[st][mp[f.second][i].first]<=f.first){
				f.first-=mp[f.second][i].second;
				continue;
			}
			ds[st][mp[f.second][i].first]=f.first;
			//cout<<sub[mp[f.second][i].first].size()<<endl;
			for(int j=0;j<(int)(sub[mp[f.second][i].first].size());j++){
				//cout<<j<<endl;
				//while(!q.empty()){
				//   	f=q.top();
				//	cout<<f.first<<' '<<f.second<<endl;
				//	q.pop();
				//}
				ll x=(f.first+sub[mp[f.second][i].first][j].second);
				int y=sub[mp[f.second][i].first][j].first;
				//cout<<x<<' '<<y<<endl;
				q.push({x,y});
			}
			f.first-=mp[f.second][i].second;
		}
	}
	return dm[st][m];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,d,q;
	cin>>c>>n>>m>>d>>q;
	ds.resize(m+1);
	dm.resize(m+1);
	vector<int>w;
	for(int i=0;i<m;i++){
		
		ds[i].resize(n+1);
		dm[i].resize(m+1);
		cin>>c;
		w.push_back(c);
	}
	ds[m].resize(n+1);
	dm[m].resize(m+1);
	mp.resize(m+1);
	sub.resize(n+1);
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		while(k--){
			int a,b;
			cin>>a>>b;
			mp[a].push_back({i,b});
			sub[i].push_back({a,b});
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<w[a-1]+w[b-1]+dijkstra(a,b)<<endl;
	}
	return 0;
}
