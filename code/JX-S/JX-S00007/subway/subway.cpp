#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define I return
#define love 0
#define Sasuke ;
#define forever ;
const int N = 5005,M = 5e5 + 10;
vector<pair<int,int>> v[1005];
int c,n,m,d,q,a[N][N],len[M],t[N][N],cal[N][N],num[M],dp[N][N],dis[M],vis[M],sum[N][N];
void dij(int x) {
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({0,x});
	dis[x] = 0;
	while(!q.empty()) {
		int val = q.top().first,u = q.top().second;
		q.pop();
		if(vis[u] == 1) continue;
		vis[u] = 1;
		for(int i = 0; i < v[u].size(); i++) {
			int vv = v[u][i].first,w = v[u][i].second;
			if(dis[vv] > dis[u] + w) dis[vv] = dis[u] + w,q.push({dis[vv],vv});
		}
	}
}
void bfs(int x) {
	queue<int> q;
	q.push(x);
	dis[x] = 0;
	vis[x] = 1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < v[u].size(); i++) {
			int vv = v[u][i].first,w = v[u][i].second;
			if(vis[vv] == 0) {
				vis[vv] = 1;
				dis[vv] = dis[u] + 2;
				q.push(vv);
			}
		}
	}
}
vector <int> s[400005];
int main() {
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  ios
  cin >> c >> n >> m >> d >> q;
  memset(cal,0x3f,sizeof(cal));
  int g = 0;
  for(int i = 1; i <= m; i++) cin >> num[i];
  for(int i = 1; i <= n; i++) {
	  cin >> len[i];
	  for(int j = 1; j <= len[i]; j++) {
		  cin >> a[i][j] >> t[i][j];
		  g = t[i][j];    
		  s[a[i][j]].push_back(i);
	  }
	 
  }
  if(c >= 12 && c <= 15) {
    for(int i = 1; i <= m; i++) {
	   for(int j = 0; j < s[i].size();j++) {   
		   int k = s[i][j];
		   for(int l = 1; l <= len[k]; l++) if(i != l) v[i].push_back({l,1});
	  }
	     for(int i = 1; i <= m; i++) dis[i] = 0,vis[i] = 0;
	     bfs(1);
	    while(q--) {
	  int x,y;
	  cin >> x >> y;
	  cout << x << y << endl;
	  cout << num[x] + num[y] + (dis[y] - dis[x]) * g << '\n';
     }
  }
  } else {
	  for(int i = 1; i <= n; i++) {
	   for(int j = 1; j <= len[i]; j++) {   
		   for(int l = 1; l <= len[i]; l++) cal[a[i][l]][a[i][j]] = min(cal[a[i][l]][a[i][j]],t[i][l] + t[i][j]);
	  }
	 
  }
	 for(int i = 1;i <= m; i++) {
	  for(int j = 1; j <= m; j++) {
		  if(cal[i][j] < 1e9 && i != j) v[i].push_back({j,cal[i][j]});
	  }
  }
  if(q <= 200) {
	  while(q--) {
	  int x,y;
	  cin >> x >> y;
	   for(int i = 1; i <= m; i++) dis[i] = 1e9,vis[i] = 0;
	   dij(x);
	   cout << num[x] + num[y] + dis[y] << '\n';
  }
  } else if(c <= 11){
	  for(int i = 1; i <= m; i++) {
		  for(int j = 1; j <= m; j++) dis[j] = 1e9,vis[j] = 0;
	      dij(i);
	        for(int j = 1; j <= m; j++) sum[i][j] = dis[j];
	  }
	    while(q--) {
	  int x,y;
	  cin >> x >> y;
	   cout << num[x] + num[y] + sum[x][y] << '\n';
       }
   }
}
  I love Sasuke forever 
}
/*
 0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
 */
