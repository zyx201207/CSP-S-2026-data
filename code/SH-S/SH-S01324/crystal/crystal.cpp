#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
int n, ed;
ll a[N], m, ans, sum;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	ans = 0; ed = 1;
	sum = 0;
	for(ll i = 1; i <= n; i++){
		sum += (a[i]-a[i-1])*(i-ed);
//		cout << i << " " << sum << " " << ed << "\n";
		if(sum <= m){
			ans = max(ans, i-ed+1);
		}else{
			while(sum > m){
				sum -= a[i]-a[ed];
				ed++;
			}
		}
	}
	cout << ans;
	return 0;
}
