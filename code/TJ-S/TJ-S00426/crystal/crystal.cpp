#include <bits/stdc++.h>
using namespace std;
#define int long long
const int Max = 1e12 + 5;
int n,m;
int a[500005];
int l = Max,r = -Max;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool f = 1,f2 = 1;
	int ct = 0;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		l = min(l,a[i]);
		r = max(r,a[i]);
		if(a[i] != i) f = 0;
		if(i == 1){
	  		continue;
		}
		else if(i == 2){
			ct = a[i] - a[i - 1];
			continue;
		} else {
			if(a[i] - a[i - 1] != ct){
				f2 = 0;
			}
		}
	} 
	if(f == 1){//15分 
		int idx = 1;
		int cnt = 1;
		while(m - idx >= 0 && cnt < n){
			m -= idx;
			idx++;
			cnt++;
		}
		cout << cnt;
		return 0;
	}
	if(f2 == 1){//15分 
		int idx = ct;
		int cnt = 1;
		while(m - idx >= 0 && cnt < n){
			m -= idx;
			idx *= 2;
			cnt++;
		}
		cout << cnt;
		return 0;
	} 
	sort(a + 1,a + 1 + n);//尝试 
	int mx = -1005,ans = 0;
	for(int i = l;i <= r; i++){//数值 
		int cnt = 0,cnt2 = 0;
		int x = m;
		for(int j = 1;j <= n; j++){
			if(i - a[j] >= 0 && x - (i - a[j]) >= 0){
				x -= (i - a[j]);
				cnt += (i - a[j]);
				cnt2++; 
			}
		}
		if(cnt <= m && cnt2 >= mx){
			mx = cnt2;
			ans = max(ans,cnt2);
		}
	}
	cout << ans;//成功 
	return 0;
}
