#include<bits/stdc++.h>
using namespace std;
#define int long long
#define LYT ios::sync_with_stdio(0),cin.tie(0)
const int N = 5e5 + 10;
int n,m,a[N],sum[N],ans,ans1,s[N];
bool check(int x){
	int sum = 0,ans1 = 0;
	for(int i = x;i >= 1;i--){
		sum += a[x] - a[i];
		ans1++;
		if(sum > m){
			ans = max(ans,ans1 - 1);
			int jz = (s[n] - s[i - 1]) / (n - i + 1);
			int jz2 = (s[i]) / i;
			if(a[i] - jz2 > jz - a[i]) return 1;
			else return 0;
		}
	}
	ans = max(ans,ans1);
	double jz = (s[n] - s[x - 1]) / (n - x + 1);
	double jz2 = (s[x]) / x;
	if(a[x] - jz2 > jz - a[x]) return 1;
	else return 0;
}
void solve2(){
	int pos = n,ans = 0;
	for(int i = pos;i >= 1;i--){
		if(m - (a[pos] - a[i]) >= 0) m -= a[pos] - a[i],ans++;
	} 
	cout << ans;
}
signed main(){LYT;
//	freopen("s.txt","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
	if(n <= 5000) for(int i = 1;i <= n;i++) check(i);
	else{
		bool bb = 0;
		for(int i = 2;i < n;i++) if(a[i] - a[i-1] != a[i+1] - a[i]) bb = 1;
		if(bb == 0){
			solve2();
			return 0;
		}
		int l = 1,r = n;
		while(l <= r){
			int mid = (l + r) / 2;
			if(check(mid)) r = mid - 1;
			else l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}

