#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
struct node{
	int i,tm;
};
int c, n, m, d, q;
int w[N], num[N];
vector<int> mp[N];
vector<node> tim[N];
int vis[N];
node times[N];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	memset(times, 0x3f, sizeof times);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	int k;
	cin >> k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2*k;j++){
			int ai, ti;
			cin >> ai >> ti;
			mp[i].push_back(ai);
			tim[j].push_back({i, ti});
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		queue<int> q;
		q.push(x);
		while(!q.empty()){
			int f = q.front();
			for(int i=0;i<mp[f].size();i++){
				if(!vis[i]) q.push(mp[f][i]);
				vis[i] = 1;
				times[i] = min(times[f] + tim[f][i].tm, times[i]);
			}
		}
		cout << times[i] << '\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
