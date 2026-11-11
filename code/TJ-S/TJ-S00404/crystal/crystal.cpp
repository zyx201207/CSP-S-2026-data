#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 501000;

ll n,m,ans;
ll l,r,mid;
ll a[N];

ll check(ll mid) {
	ll sum = 0;
	for(ll i = n;i >= 1;i --) {
		if(a[mid] > a[i]) sum += (a[mid] - a[i]); 
	}
	if(sum <= m) return true;
	else return false;
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(ll i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1,a + n + 1);
	l = 1;
	r = n;
	int t = 0;
	while(l < r) {
		mid = (l + r) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
		if(l == r - 1) 	t ++;
		if(t >= 10 || l == r) break;
//		cout << "l:" << l <<" r:" << r << endl;
	}
	
	cout << l;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
