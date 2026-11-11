#include <bits/stdc++.h>
using namespace std;
const int M = 6e5+ 5;
int w[M],a[505][M],t[505][M];
int k[505];
vector<pair<int,int>> e[505];
int c,n,m,d,q;
int tx;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
   	cin >> c>> n >> m >> d >> p;
   	for(int i = 1;i <= m;i++)cin >> w[i];
   	for(int i = 1;i <= n;i++){
   		cin >> k[i];
   		int find_x,find_y;
		for(int j = 1;j <= k;j++){
			cin >> a[i][j] >> t[i][j];
			e[a[i][j]].push_back({i,t[i][j]});
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		int ans = w[x]+w[y];
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= k[i];j++){
				
			}
		}
	}
}