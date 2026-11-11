# include <bits/stdc++.h>
using namespace std;

const int N = 5 * 1e3+5;
int c,n,m,d,q;
int w[N];
int k;
struct aox{int v,e;};
vector<aox> a[N];	
//a[i][j].v   i连接的第j条边是v  
//a[i][j].e   i连接的第j条边长度为e 

int dij(int st,int ed){
	bool v[N] = {0};
	priority_queue< pair<int,int> > q;
	q.push({0,st});
	while(!q.empty()){
		pair<int,int> t = q.top();
		q.pop();
		if(t.second == ed) return w[st] + t.first + w[ed];
		int len = a[t.second].size();
		for(int i = 0;i < len;i++){
			if(!v[a[t.second][i].v]){
				v[a[t.second][i].v] = 1;
				q.push({t.first + a[t.second][i].e,a[t.second][i].v });
			}
		}
	}
	return 0;
} 


signed main(){
	int x,y;
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> x >> y;
			a[i].push_back({x,y});
			a[x].push_back({i,y});
		}
	}
	
	
	
	
	while(q--){
		cin >> x >> y;
		cout << dij(x,y)<<"\n";
	}
	
	return 0;
} 