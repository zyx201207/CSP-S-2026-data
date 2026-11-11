#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,n,m,d,q;
vector <pair <int,int>> a[N];
int w[N];
int dis[N];
int solve(int x,int y){
	for (int i=1;i<=n+m;i++) dis[i]=2e18;
	queue <int> q;
	q.push(x);
	dis[x]=0;
	while (!q.empty()){
		int u=q.front();
		q.pop();
		for (auto it:a[u]){
			int l=it.first,r=it.second;
			if (dis[l]>dis[u]+r){
				q.push(l);
				dis[l]=dis[u]+r;
			}
		}
	}
	int ans=dis[y];
	return ans;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++) cin >> w[i];
	for (int i=1;i<=n;i++){
		int k;
		cin >> k;
		for (int j=1;j<=k;j++){
			int x,t;
			cin >> x >> t;
			a[x].push_back({i+m,t});
			a[m+i].push_back({x,t});
		}
	}
	while (q--){
		int x,y;
		cin >> x >> y;
		cout << solve(x,y)+w[x]+w[y] << '\n';
	}
	return 0;
}
