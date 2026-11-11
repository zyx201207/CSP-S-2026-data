#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5 + 5;
int c,n,m,d,q;
ll w[maxn];
struct P{
	int k;
	vector<int> a;
	vector<ll> t;
}a[505];
vector<pair<int,int> > e[maxn];

ll dis[maxn];
void dij(int u){
	for (pair<int,int> i:e[u]){
		for (int j = 0;j < a[u].a.size();j ++){
			ll w = a[i.first].t[i.second] + a[i.first].t[j];
//				cout << w << " " << a[i.first].t[i.second] << "- ";
			if (dis[u] + w < dis[a[i.first].a[j]]){
				dis[a[i.first].a[j]] = dis[u] + w;
				dij(a[i.first].a[j]);
			}
		}
	}
//		cout << "\n";
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i ++){
		cin >> w[i];
	}
	for (int i = 1;i <= n;i ++){
		cin >> a[i].k;
		for (int j = 1;j <= a[i].k;j ++){
			int x;
			ll y;
			cin >> x >> y;
			a[i].a.push_back(x);
			a[i].t.push_back(y);
			e[x].push_back({i,j - 1});
		}
	}
	
	while (q --){
		int x,y;
		cin >> x >> y;
		for (int i = 1;i <= m;i ++){
			dis[i]= 1e18;
		}
		dis[x] = 0;
		dij(x);
		cout << w[x] + w[y] + dis[y] << "\n";
	}
	return 0;
}