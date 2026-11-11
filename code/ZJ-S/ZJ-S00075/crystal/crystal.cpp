#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define PII pair<int,int>
#define db double
const int N  = 5e5+5;
const int inf = 1e18;
int n,m;
int a[N];
int sum[N];
int check(int mid){
	int l = 1;
	for(int r = 1;r <= n;r++){
		int t = sum[r]-sum[l-1]-a[r]*(r-l+1);
		t *=-1;
		while(t>m&&l<=r){
			t-=a[r]-a[l];
			l++;
		}
		if(r-l+1>=mid)return 1;
	}
	return 0;
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l = 1,r = n;
	int ans = 1;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)){
			l = mid + 1;
			ans = mid;
		}
		else{
			r = mid - 1;
		}
	}
	cout << ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
	// cin >> _;
	while(_--)solve();
	return 0;
}
/*
kao lv er fen da an
check(){
	kao lv yi ge shui jing
	tan xin rang qian mian de shui jing bian cheng ta
}
14:47
*/
