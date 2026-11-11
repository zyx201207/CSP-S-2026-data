#include <bits/stdc++.h>
using namespace std;

const int N = 2e6;

int c,t,n,d;
int x[N];
int p[310];

bool f,f2;

void dfs(int u,int ans,int l){
	if (f)return;
	if (u == ans){
		p[l]++;
		return;
	}
	for (int i = u+1 ; i <= n ; i++){
		if (x[i]-x[u] > d)break;
		dfs(i,ans,l+1);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while (t--){
		int ans = 0;
		cin >> n >> d;
		for (int i = 1 ; i <= n ; i++){
			cin >> x[i];
		}
		for (int i = 1 ; i <= n ; i++){
			for (int j = i+1 ; j <= n ; j++){
				f = 0;
				dfs(i,j,0);
				for (int i = 1 ; i <= n ; i++){
					if (p[i] == 2){
						ans++;
						break;
					}
					if (p[i])break;
				}
				for (int i = 1 ; i <= n ; i++){
					p[i] = 0;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
