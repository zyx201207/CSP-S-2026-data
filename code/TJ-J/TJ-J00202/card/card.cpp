#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[300005],b[500005],flag[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> b[i];
		a[i] = b[i];
	}
	for (int w = 1; w <= n; w++){
		for (int i = w; i <= n; i++){
			int k = 0;
			for (int j = w; j < i; j++){
				if (k){
					a[j] = 0;
					continue;
				}
				if (a[j] == a[i]){
					k = 1;
					a[j] = 0;
				}
			}
		
		}
		for (int j = w; j <= n; j++){
			if (a[j] != 0 && flag[j] == 0){
				ans[a[j]]++;
				flag[j] = 1;
			}
		}
		for (int j = w; j <= n; j++){
			a[j] = b[j];
			flag[a[j]]= 0;
		}
	}	
	for (int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
