#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 10;
int n,ans;
ll a[N],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	sort(a + 1,a + 1 + n);
	ll res = 0;
	for(int r = 1,l = 1 ; r <= n ; r ++){
		res += (r - l) * (a[r] - a[r - 1]);
		while(l <= r && res > m){
			l ++;
			res -= (a[r] - a[l - 1]);
		}
		ans = max(ans,r - l + 1);
	}
	cout << ans;
	return 0;
}