#include <bits/stdc++.h>

using namespace std; 

vector<vector<pair<int,int> > > b(500005);     //直达站 时间 编号 
vector<vector<int> > d(502);
vector<vector<int> > e(500005); 
vector<bool> visited(500005);
vector<int> ans(500005,INT_MAX);
vector<int> lin(1000003);

int c,n,m,D,q;
int k,a,t;

vector<int> station(500005);

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> D >> q;
	for (int i = 1;i <= m;i++){
		cin >> station[i];
	}
	for (int i = 1;i <= n;i++){
		cin >> k;
		for (int j = 1;j <= k;j++){
			cin >> a >> t;
			d[i].push_back(a);  //i号线有站台a; 
			e[a].push_back(i);  //a站台有线i号； 
			b[i].push_back(make_pair(t,a)); //b号线上a站台时间t; 
		}
		//cout << k << "\n";
		//cout << a << "\n"; 
	}
	/* 
	for (int i = 1;i <= n;i++){
		for (int j = 0;j < (int)d[i].size();j++){
			cout << d[i][j] <"\n";
		}
	}
	*/ 

	for (int i = 1;i <= q;i++){
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
		int x,y;
		cin >> x >> y;
		pq.push(make_pair(0,x));
		/*
		for (int j = 0;j < (int)e[x].size();j++){
			int line = e[x][j];
			for (int k = 0;k < (int)b[line].size();k++){
				pq.push(b[line][k]);
			}
		}
		*/

		while (!pq.empty()){
			int time = pq.top().first;
			int st = pq.top().second;
			if (visited[st]) continue;
			visited[st] = true;
			ans[st] = time;
			if (st = y) {
				cout << ans[st] << "\n";
				break;
			}
		//b[i].push_back(make_pair(t,a)); //b号线上a站台时间t;
			for (int j = 0;j < (int)e[st].size();j++){
				int line = e[st][j];
				for (int k = 0;k < (int)b[line].size();k++){
					int v,u;
					v = b[line][k].first;
					u = b[line][k].second;
					if (b[line][st].first + u + time < ans[u]){
						pq.push(make_pair(b[line][st].first + u + time,u));
					}
				}
			}
		}
	

		b.clear();
		d.clear();
		e.clear();
		visited.clear();
		ans.clear();			
	} 
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
