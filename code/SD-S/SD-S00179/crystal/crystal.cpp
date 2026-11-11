#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	bool flag = 1;
	cin >> n >> m;
	cin >> a[1];
	int cha,maxn = a[1],minn = a[1];
	for(int i = 2;i <= n;i++){
		cin >> a[i];
		if(i == 2) cha = a[2] - a[1];
		if(a[i] - a[i - 1] != cha) flag = 0;
		maxn = max(maxn,a[i]);
		minn = min(minn,a[i]);
	} 
	if(flag){
		int sum[63] = {0,cha};
		if(m < sum[1]){
			cout << 1;
			return 0;
		}
		for(int i = 2;i <= 61;i++){
			sum[i] = sum[i - 1] + cha * i;
			if(sum[i] > m){
				cout << i;
				return 0;
			}
		} 
	}
	sort(a + 1,a + 1 + n);
	int maxa = -LLONG_MAX;
	for(int i = 1;i <= n;i++){
		int ans = 0;
		int cm = m;
		int ii = i;
		while(cm > 0){
			if(ii < 1){
				break;
			}
			ans++;
			cm -= (a[ii] <= 0 ? abs(a[ii]) + a[i] : a[i] - a[ii]);
			ii--;
		}
		if(cm < 0) ans--;
//		cout << ans << endl;
		maxa = max(maxa,ans);
	}
	cout << maxa;	
	return 0;
}

