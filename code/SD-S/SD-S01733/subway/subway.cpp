#include<bits/stdc++.h>
using namespace std;

inline long long Mmin(long long a,long long b){
	return a<b?a:b;
}

inline long long rd(){
	long long x = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){if(c=='-')f=-1;c = getchar();}
	while(c >= '0' && c <= '9')x = x*10 + c - '0' , c = getchar();
	return x*f;	
}


long long dis[502][50004],c,n,m,d,q,w[500005];
int dis2[502][500505];
vector<pair<int,long long> > mp[500505];

class Node{
	public:
		long long w;
		int id;
		Node(){}
		Node(int i,long long ww) : id(i) , w(ww) {}
		friend bool operator <(const Node &a,const Node &b){
			return a.w > b.w;
		}
};

void dij(int x,long long d[]){
	vector<bool> vis(n+m+1,0);
	priority_queue<Node> q;
	d[x] = 0;
	q.push(Node(x,0));
	while(!q.empty()){
		Node p = q.top();
		q.pop();
		vis[p.id] = 1;
		for(auto item : mp[p.id]){
			int v = item.first , w = item.second;
			if(d[v] > d[p.id] + w){
				d[v] = d[p.id] + w;
				if(!vis[v])
					q.push(Node(v,d[v]));
			}
		}
		
	}
}

void bfs(int x,int d[]){
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(pair<int,long long> item : mp[p]){
			int u = item.first;
			if(d[u] == 0 && u != x){
				d[u] = d[p]+1;
				q.push(u);
			}
		}
	}
}

int main(){
	ios :: sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = rd(); n = rd(); m = rd(); d = rd(); q = rd();
	for(int i = 1; i <= m; i++)
		w[i] = rd();
	if(c >= 12 && c <= 19)goto pian;
	for(int i = 1,k; i <= n; i++){
		k = rd();
		for(int j = 1,v,t; j <= k; j++){
			v = rd();t = rd();
			mp[i + m].push_back({v,t});
			mp[v].push_back({i+m,t});
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m+n+1; j++)
			dis[i][j] = LLONG_MAX;
		dij(m+i,dis[i]);
	}
	
	while(q--){
		int u,v;
		long long ans = LLONG_MAX; 
		u = rd(); v = rd();
		for(int i = 1; i <= n; i++)
			ans = Mmin(ans,dis[i][u] + dis[i][v]);
		cout << (ans+w[u]+w[v]) << '\n';
	}
	return 0;
	
	
	pian:
		
		
	long long ww;
	for(int i = 1,k; i <= n; i++){
		k = rd();
		for(int j = 1,v,t; j <= k; j++){
			v = rd();t = rd();
			ww = t;
			mp[i + m].push_back({v,t});
			mp[v].push_back({i+m,t});
		}
	}
	
	for(int i = 1; i <= n; i++)
		bfs(i,dis2[i]);
	while(q--){
		int u,v;
		long long ans = LLONG_MAX; 
		u = rd(); v = rd();
		for(int i = 1; i <= n; i++)
			ans = Mmin(ans,ww*(dis2[i][u] + dis2[i][v]));
		cout << (ans+w[u]+w[v]) << '\n';
	}
	
	return 0;
}


