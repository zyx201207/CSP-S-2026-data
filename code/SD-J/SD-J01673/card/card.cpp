#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[500005],ans[500005];
long long xba[500005]; //存储a[i]第一次出现的下标 
bool bj[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int k = 1; k <= n; k++){
		int xb;
		for (int i = 1; i <= m; i++){
			bj[i] = 0;
		}
		xb = 0;
		for (int i = k; i <= n; i++){
			if (bj[a[i]]== 0){
				xb++;
				b[xb] = a[i];
				bj[a[i]] = 1;
				xba[a[i]] = xb; 
			}
			else{
				for (int j = xba[a[i]]; j <= xb; j++){
					b[j] = 0;
				}
				xb = xba[a[i]];
				b[xb] = a[i];
				}

		}	
		for (int i = 1; i <= xb; i++){
			ans[b[i]]++;
		}
	}
	for (int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
