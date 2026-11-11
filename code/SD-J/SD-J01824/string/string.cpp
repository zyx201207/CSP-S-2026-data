#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200002];
char c[200002];
char v[200002];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 1;i <= n;i ++){
		cin >> a[i] >> c[i];
		for(int j = 1;j <= a[i];j ++){
			v[++ cnt] = c[i];
		}
	}
	int ans = 0;
	if(cnt % 2){
		int mid = cnt / 2 + 1;
		for(int l = mid - 1,r = mid + 1;l >= 1 && r <= cnt;l --,r ++){
			if(v[l] != v[r]){
				ans ++;
			}
		}
	}
	else{
		int mid = cnt / 2;
		for(int l = mid,r = mid + 1;l >= 1 && r <= cnt;l --,r ++){
			if(v[l] != v[r]){
				ans ++;
			}
		}
	}
	cout << ans;
	return 0;
} 
