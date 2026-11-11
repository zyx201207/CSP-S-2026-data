#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int maxx = 0;
	int yv;
	int minn = INT_MAX;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(i == 1){
			yv = a[i];
		}else{
			yv &= a[i];
		}
		minn = min(minn,a[i]);
		maxx = max(maxx,a[i]);
	}
	if(m == 1){
		cout << maxx;
		return 0;
	}
	if(m == n){
		cout << yv;
		return 0;
	}
	if(m == 2){
		int ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i == j){
					continue;
				}
				ans = max(ans,a[i] & a[j]);
			}
		}
		cout << ans;
	}
	cout << minn;
	return 0;
}
