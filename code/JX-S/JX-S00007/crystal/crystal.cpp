#include<bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define I return
#define love 0
#define Sasuke ;
#define forever ;
const long long N = 5e5 + 10;
long long n,m,a[N],sum[N];
long long cal(long long l,long long r) {return sum[r] - sum[l - 1];}
long long cal2(long long id,long long k) {
	long long l = 1,r = id,ans = 0,e = 0;
	while(l <= r) {
		long long mid = (l + r + 1) >> 1;
		if(mid * k - cal(id - mid + 1,id) <= m) {
			ans = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	//cout << ans << '\n';
	return ans;
}
int main() {
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  ios
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  long long ans = 0;
  for(int i = 1; i <= n; i++) ans = max(ans,cal2(i,a[i]));
  cout << ans;
  I love Sasuke forever 
}
/*
 5 5
 1 2 4 8 9
 
 5 8
-3 -1 2 2 7
 */
