#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 510;
const int M = 5e5 + 3;
int n,m,d,q;
ll T;
ll w[M], t[N][N];
vector<int> e[N];
bool vis[N][N];

int main(){
	IOS;
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c;
	cin >>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++){
		cin >>w[i];
	}
//	cout <<"step 1 \n";
	for(int i = 1;i <= n;i++){
		int k;
		cin >>k;
		for(int j = 1;j <= k;j++){
			int x;
			ll y;
			cin >>x>>y; 
			T = y;
		}
	}
//	cout <<"step 2 \n";
	while(q--){
		int x,y;
		cin >>x>>y;
		
		ll ans = 1e18;
		queue< pair<int, ll> > q;
		q.push(make_pair<int, ll>(x, w[x] + T));
		while(!q.empty()){
			pair<int, ll> node = q.front();
			q.pop();
			int now = node.first;
			
			for(int i = 0;i < e[now].size();i++){
				int to = e[now][i];
				if(vis[now][to]) continue;
				vis[now][to] = 1;
				
				if(to == y){
					if(node.second + T + w[y] < ans) {
						ans = node.second + T * 2;
					}
					continue;
				}
				
				if(node.second + T * 2 >= ans) continue;
				
				q.push(make_pair<int, ll>(to, node.second + T * 2));
			}
		}
		
		cout <<ans<<'\n';
	}
}
