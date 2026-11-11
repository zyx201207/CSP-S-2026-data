#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5e5 + 5;

int n;
ll m;
ll a[N];
int ans = 0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	sort(a + 1,a + n + 1);	
	
	int l = n,r = n;
	ll cnt = 0;
	
	while(l >= 1 && r >= l){
		if(cnt + (a[r] - a[l]) <= m){
			cnt += (a[r] - a[l]);
		}
		else{
			r--;
			cnt -= ((a[r+1] - a[r]) * (r - l));
			continue;
		}
		
		l--;		
		
		ans = max(ans,r - l);
	}
	
	cout << ans;
	
	return 0;
}