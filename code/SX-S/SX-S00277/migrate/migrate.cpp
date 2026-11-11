#include<bits/stdc++.h>
using namespace std;
int c,t,x[114514],vis[114514];
vector<pair<int, int> >vec[114514];
priority_queue<pair<int, int> >que;

void dijkstra(int ts,int te) {
	que.push({0,ts});
	while(!que.empty()) {
		int u=que.pop().second;
		que.pop();
		for(auto k:vec) {

		}
	}
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>c>>t;
	int n,d;
	while(t--) {
		cin>>n>>d;
		for(int i=1; i<=n; ++i) {
			cin>>x[i];
		}
		for(int i=1; i<=n; ++i)
			for(int j=i; j<=n; ++j) {
				if(abs(x[i]-x[j])<=d) {
					vec[i].push_back({-abs(x[i]-x[j]),j});
					vec[j].push_back({-abs(x[i]-x[j]),i});
				}
			}
		for(int i=1; i<=n; ++i)
			for(int j=i; j<=n; ++j) {
				dijkstra(i,j);
			}
	}
	return 0;
}