#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
vector<vector<pair<int,int>>> g;
vector<vector<pair<int,int>>> kg;
vector<vector<int>> a;
vector<vector<int>> t;
vector<vector<int>> Dis;
int c,n,m,d,q;
int tt[500005];
map<int,int> mp;
vector<int> dij(int s){
	vector<int> dis;
	dis.resize(n+2);
	fill(dis.begin(),dis.end(),1e9);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,s});
	dis[s]=0;
	while(!pq.empty()){
		auto tmp=pq.top();
		int u=tmp.second;
		pq.pop();
		for(auto i:g[u]){
			int w=i.second;
			int v=i.first;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
	return dis;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	a.resize(n+1);
	t.resize(n+1);
	for(int i=1;i<=m;i++){
		cin>>tt[i];
	}
	vector<int> pts;
	vector<int> ls;
	kg.resize(500005+n);
	int K=500005;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y; 
			a[i].push_back(x);
			t[i].push_back(y);
			kg[x].push_back({K+(i+1),y});
			kg[500005+(i+1)].push_back({x,y});
			pts.push_back(x);
			if(mp[K+i+1]==0)
				ls.push_back(K+(i+1));
			mp[(K+i+1)]=1;
		}
	}
	int k=K;
	g.resize(ls.size()+1);
	Dis.resize(ls.size()+1);
//	cout<<"0================="<<endl;
	for(int u:ls){
		for(auto x:kg[u]){
			int v=x.first;
			int w=x.second;
			for(auto y:kg[v]){
				int vv=y.first;
				int ww=y.second;
				g[u-k-1].push_back({vv-k-1,w+ww});
				g[vv-k-1].push_back({u-k-1,w+ww});
			}
		}
	}
//	cout<<ls.size()<<endl;
//	cout<<"1=============="<<endl;
	int num=0;
	for(int s:ls){
		Dis[s-k-1]=dij(s-k-1);
//		cout<<s-k-1<<endl;
//		if(num==19200)system("pause");
	}
	while(q--){
		int x,y;
//		cout<<"2==============="<<endl;
		cin>>x>>y;
		int _min=1e9;
		for(auto i:kg[x]){
			int u=i.first-k-1;
			int w1=i.second;
			for(auto j:kg[y]){
				int v=j.first-k-1;
				int w2=j.second;
				_min=min(_min,Dis[u][v]+w1+w2);
			}
		}
		cout<<_min+tt[x]+tt[y]<<endl;
	}
	return 0;
}
