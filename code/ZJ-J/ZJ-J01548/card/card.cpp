#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],b[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	if (a[1] <= a[2] && a[2] <= a[3] && a[n - 1] <= a[n]){
		for (int i = 1;i <= n;i++){
			set<int> se;
			for (int j = i;j <= n;j++) se.insert(a[j]);
			for (int x : se) b[x]++;
		}
	}
	else{
		for (int i = 1;i <= n;i++){
			int f[n + 1],v[m + 1];
			int top = 0;
			for (int k = i;k <= n;k++){
				if (v[a[k]] == 1){
					while (f[top] != a[k]){
						v[f[top]] = 0;
						top--;
					}
				}
				else{
					f[top] = a[k];
					top++;
					v[a[k]] = 1;
				}
			}
			while (top >= 0){
				int u = f[top];
				b[f[top]]++;
				top--;
			}
		}
	}
	for (int i = 1;i <= m;i++) cout << b[i] << " ";
	return 0;
}//AFO.I hate Win 7.F***.100 + 56 + 100? + 12? = 156 ~ 304 
