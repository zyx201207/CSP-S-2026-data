#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int a[N], d[N], ans[N];
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++){
		for(int j = i; j <= n; j ++){
			if(d[a[j]] != 0){
					for(int k = d[a[j]]; k < j; k ++){
						vis[a[k]] = false;
						d[a[k]] = 0;
					}
				}
				vis[a[j]] = true;
				d[a[j]] = j;
		}
		for(int j = 1; j <= m; j ++){
			if(vis[j]) ans[j] ++;
			vis[j] = false;
			d[j] = 0;
		}
	}
	for(int i = 1; i <= m; i ++){
		cout << ans[i] << ' ';
	}
	return 0;
}