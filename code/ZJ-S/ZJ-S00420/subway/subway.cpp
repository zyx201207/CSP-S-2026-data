#include<bits/stdc++.h>
#define ll long long

using namespace std;
//Floyd
struct node{
	int d, t;
};
struct node2{
	int v, xl;
};
const int N = 510, S = 5e5 + 10;
int c, n, m, d, q, w[S], v[S], RP;
vector<node> k[N];
vector<node2> g[S];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++)
		cin >> w[i];
	for(int i = 1;i <= n;i ++){
		int gs;
		cin >> gs;
		for(int j = 1;j <= gs;j ++){
			int zt, ti;
			cin >> zt >> ti;
			k[i].push_back({zt, ti});
		}
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 0;j < k[i].size();j ++){
			for(int c = j + 1;c < k[i].size();c ++){
//				g[k[j].d].push_back({k[c].d, i});
			}
		}
	}
	while(q --){
		int s, e;
		queue<int> q;
		cin >> s >> e;
		cout << RP ++;
	}
	return 0;
}

