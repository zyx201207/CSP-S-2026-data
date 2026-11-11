#include<bits/stdc++.h>
using namespace std;
int n, m, b[500050], cnt[300050];
int a[500050], v[500050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	for(int o = 1; o <= n; o++){
		memset(a, 0, sizeof(a));
		memset(v, 0, sizeof(v));
		int k = 0;
		for(int i = o; i <= n; i++){
			int x;
			x = b[i];
			if(v[x] == 0){
				v[x] = ++k;
				a[k] = x;
			}
			else if(v[x] != 0){
				int y = v[x];
				for(int j = v[x]; j <= k; j++){
					v[a[j]] = 0;
					a[j] = 0;
				}
				k = y;
				v[x] = k;
				a[k] = x;
			}
		}
		for(int j = 1; j <= m; j++){
			if(v[j] != 0){
				cnt[j]++;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		cout << cnt[i] << ' ';
	}
	return 0;
}

