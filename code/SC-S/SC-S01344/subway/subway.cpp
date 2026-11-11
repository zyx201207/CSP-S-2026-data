#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
	ll v,w;
};
const int N = 5e5 + 5;
vector<node>vec[N];
int a[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		int k,sum = 0;
		cin >> k;
		for(int i = 1;i <= n;i++){
			int u,v,w;
			cin >> u >> v >> w;
			vec[u].push_back({v,w});
			vec[v].push_back({u,w});
			sum += w;
		}
		cout << sum << "\n";
	}
	//dji忘了
	return 0;
}
