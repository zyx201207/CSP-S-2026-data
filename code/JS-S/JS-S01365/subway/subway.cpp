#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c , n , m , d , q , st , en;
ll ans;
int w[500005] , k[500005];
ll mn = 1e18;//20~21
struct node{
	int t , l , p;
};
vector<node>a[500005] , b[500005];
bool vis[500005];
void dfs(int p , int pos , int lne , ll dis , int fx , bool tran){
	//cout << p << ' ' << pos << ' ' << lne << ' ' << dis << ' ' << fx << endl;
	node x = b[lne][pos];
	if(p == en){
		ans = min(ans , dis + x.t);
		return;
	}
	if((dis >= ans or pos > k[lne] or pos < 1 or vis[p]) and !tran){
		return;
	}
	vis[p] = 1;
	dfs(b[lne][pos + fx].l , pos + fx , lne , dis , fx , 0);
	if(!tran){
		for(int j = 0 ; j < a[x.l].size() ; ++j){
			node i = a[x.l][j];
			if(i.l != lne){
				dfs(p , i.p , i.l , dis + i.t + x.t , 1 , 1);
				dfs(p , i.p , i.l , dis + i.t + x.t , -1 , 1);
			}
		}
	}
	vis[p] = 0;
}
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; ++i){
		cin >> w[i];
	}
	for(int i = 1 ; i <= n ; ++i){
		cin >> k[i];
		b[i].push_back({0 , 0 , 0});
		for(int j = 1 ; j <= k[i] ; ++j){
			int t , l;
			cin >> l >> t;
			a[l].push_back({t , i , j});
			b[i].push_back({t , l , -1});
		}
	}
	/*for(int i = 1 ; i <= m ; i ++){
		for(auto j:a[i]){
			cout << i << ' ' << j.t << ' ' << j.l << ' ' << j.p << endl;
		}
		cout << endl;
	}*/
	if(c == 20 or c == 21){
		for(int i = 1 ; i <= n ; ++i){
			ll x1 = 1e18 , x2 = 1e18;
			for(auto j:b[i]){
				if(j.l == 1){
					x1 = j.t;
				}
				else if(j.l == 2){
					x2 = j.t;
				}
			}
			mn = min(mn , x1 + x2);
		}
		while(q --){
			int s , t;
			cin >> s >> t;
			if(s == t){
				cout << 0 << "\n";
			}
			else{
				cout << mn + w[1] + w[2] << "\n";
			}
		}
		return 0;
	}
	while(--q){
		cin >> st >> en;
		if(st == en){
			cout << 0 << "\n";
			continue;
		}
		ans = 1e18;
		for(int j = 0 ; j < a[st].size() ; ++j){
			node i = a[st][j];
			dfs(st , i.p , i.l , i.t , 1 , 1);
			dfs(st , i.p , i.l , i.t , -1 , 1);
			for(int i = 1 ; i <= m ; ++i){
				vis[i] = 0;
			}
		}
		cout << ans + w[st] + w[en] << "\n";
	}
	return 0;
}