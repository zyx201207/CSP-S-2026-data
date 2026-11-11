#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int c[500005];
int s[500005];
int ans; 
bool check(int mid){
	int sum = 0;
	for(int i = 1;i < mid;i++)
		sum += c[i] * i;
	int l = 1,r = mid - 1;
	if(sum <= m) return 1;
	while(r < n - 1){
		sum -= (s[r] - s[l - 1]);
		r++,l++;
		sum += c[r] * (mid - 1);
		if(sum <= m) return 1;
	}
	return 0;
}
bool cmp(int x,int y){return x < y;}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr),cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	for(int i = 1;i < n;i++){
		c[i] = a[i + 1] - a[i];
		s[i] = s[i - 1] + c[i];
	}
	int l = 1,r = n;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}
	cout << ans;
	return 0;
}
