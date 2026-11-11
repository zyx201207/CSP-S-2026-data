#include <bits/stdc++.h>

using namespace std;
const int N = 5e5+10;
int n;
long long m, a[N], sum[N]; 

long long need(int l,int r){
	int len = r-l+1;
	return a[r]*len-(sum[r]-sum[l-1]); 
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	
	sort(a+1,a+1+n);
	for (int i = 1;i <= n;i++){
		sum[i] = sum[i-1]+a[i];
	}
	
	int l = 1,r = 1, ans = -1e9+10;
	while (l <= r && r <= n){
		while (need(l,r) <= m && r <= n){
			ans = max(ans,r-l+1);
			r++;	
		}
		l++;
	} 
	cout << ans;
	return 0;
}

