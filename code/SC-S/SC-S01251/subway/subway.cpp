#include<bits/stdc++.h>
using namespace std;
#define pil pair<int,long long>
const int N = 5e5+5;
int c, n, m, d, q, w[N], k[505];
struct node{
	int a, t;
};
vector<node>b[505];
vector<int>res[N];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++){
		cin >> k[i];
		for (int j = 1;j <= k[i];j++){
			int x, y;//a,t
			cin >> x >> y;
			b[i].push_back({x,y});
			res[x].push_back(i);
		}
	}
	for (int r = 1;r <= q;r++){
		long long ans = 0;
		int x, y;
		cin >> x >> y;
		if (n == 1){
			for (int j = 0;j < k[1];j++)
				if (b[1][j].a == x || b[1][j].a == y) 
					ans += b[1][j].t;
			ans = ans+w[x]+w[y];
		}
		if (n == 2){
			for (int j = 0;j < k[1];j++)
				if (b[1][j].a == x || b[1][j].a == y) 
					ans += b[1][j].t;
			ans = ans+w[x]+w[y];
		}
		cout << ans << '\n';
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/