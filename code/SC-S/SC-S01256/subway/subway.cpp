#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, n, m, d, q, x, y;
int vrr[550005];
int ans[550005];
int sc[550005];
int flag[550005];
int jl[505][50005];
int jx[10][550005];
struct node{
	vector <int> son;
	vector <int> w;
}arr[550005];

struct code{
	int bh, w;
	bool operator <(const code &p) const{
		return p.w < w;
	}
};
priority_queue <code> drr;
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> vrr[i];
	}
	for(int i = 1; i <= n; i++){
		int k = 0;
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> x >> y;
			arr[m + i].son.push_back(x);
			arr[m + i].w.push_back(y);
			arr[x].son.push_back(m + i);
			arr[x].w.push_back(y);
		}
	}
	if(c == 20 || c == 21){
		for(int k = m + 1; k <= n + m; k++){
			for(int i = 1; i <= n + m; i++){
				ans[i] = 999999999999999;
				flag[i] = 0;
			}
			int from = k;
			ans[from] = 0;
			drr.push({from, 0});
			while(drr.size()){
				int bh = drr.top().bh, w = drr.top().w;
				drr.pop();
				if(flag[bh] == 1){
					continue;
				}
				flag[bh] = 1;
				for(int i = 0; i < arr[bh].son.size(); i++){
					int son = arr[bh].son[i];
					int hf = arr[bh].w[i];
					if(ans[son] > ans[bh] + hf){
						ans[son] = ans[bh] + hf;
						drr.push({son, ans[son]});
					}
				}
			}
			for(int i = 1; i <= m; i++){
				jx[k - m][i] = ans[i];
			}
		}
		for(int i = 1; i <= q; i++){
			cin >> x >> y;
			int maxn = 9999999999999;
			for(int j = 1; j <= n; j++){
				maxn = min(maxn, jx[j][x] + jx[j][y]);
			}
			cout << maxn + vrr[x] + vrr[y] << '\n';
		}		
		return 0;
	}
	for(int k = m + 1; k <= n + m; k++){
		for(int i = 1; i <= n + m; i++){
			ans[i] = 999999999999999;
			flag[i] = 0;
		}
		int from = k;
		ans[from] = 0;
		drr.push({from, 0});
		while(drr.size()){
			int bh = drr.top().bh, w = drr.top().w;
			drr.pop();
			if(flag[bh] == 1){
				continue;
			}
			flag[bh] = 1;
			for(int i = 0; i < arr[bh].son.size(); i++){
				int son = arr[bh].son[i];
				int hf = arr[bh].w[i];
				if(ans[son] > ans[bh] + hf){
					ans[son] = ans[bh] + hf;
					drr.push({son, ans[son]});
				}
			}
		}
		for(int i = 1; i <= m; i++){
			jl[k - m][i] = ans[i];
		}
	}
	for(int i = 1; i <= q; i++){
		cin >> x >> y;
		int maxn = 9999999999999;
		for(int j = 1; j <= n; j++){
			maxn = min(maxn, jl[j][x] + jl[j][y]);
		}
		cout << maxn + vrr[x] + vrr[y] << '\n';
	}
	return 0;
 } 