#include<bits/stdc++.h>
using namespace std;


int c,n,m,d,q,k,a,x,y,o;
long long w[1000005];
long long g[10005][10005];


int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
//	
//	
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1; i <= m; ++i){
		cin>>w[i];
	}
	
	for(int i = 1; i <= n + m + 5; ++i){
		for(int j = 1; j <= n + m + 5; ++j){
			g[i][j] = 0x3f3f3f3f3f3f3f;
		}
	}
	
	for(int i = 1; i <= n; ++i){
		cin>>k;
		for(int j = 1; j <= k; ++j){
//			cout << 'f'; 
			cin >> a;
			cin >> g[a][i + m];
			
			g[i + m][a] = g[a][i + m];
//			cout<<a << ' ' << g[a][i + m] << '\n';
		}
	
	}
//	for(int j = 1; j <= m + n; ++j){
//		for(int k = 1; k <= m + n; ++k){
//			cout << g[j][k] << ' ';
//		}
//		cout << '\n';
//	}
	for(int i = 1; i <= m + n; ++i){
		for(int j = 1; j <= m + n; ++j){
			for(int k = 1; k <= m + n; ++k){
				g[j][k] = g[j][k] > (g[j][i] + g[i][k]) ? (g[j][i] + g[i][k]) : g[j][k];
			}
		}
	}
	
	for(int i = 1; i <= q; ++i){
		cin >> x >> y;
		cout << g[x][y] + w[x] + w[y] << '\n';
	}
//	for(int j = 1; j <= m + n; ++j){
//		for(int k = 1; k <= m + n; ++k){
//			cout << g[j][k] << ' ';
//		}
//		cout << '\n';
//	}
	

    return 0;
}
