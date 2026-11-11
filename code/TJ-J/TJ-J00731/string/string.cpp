#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5+7;
int n;
char s[MAXN];
ll a[MAXN], ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> n;
	ll p = 0;
	for(int i = 1;i <= n;++i){
		ll num;
		cin >> num >> s[i];
		a[i] = p+1;
		p += num;
	}
	a[n+1] = p+1;
	ll l = 1, r = a[n+1], lsub = 1, rsub = n;
	while(lsub < rsub){
		ll d = min(a[lsub+1]-l, r-a[rsub]);
		if(s[lsub] != s[rsub])
			ans += d;
		if(a[lsub+1]-l < r-a[rsub])
			lsub++;
		else if(a[lsub+1]-l == r-a[rsub]){
			lsub++;	rsub--;
		} else if(a[lsub+1]-l > r-a[rsub])
			rsub--;
		l += d;	r -= d;
	}
	cout << ans;
	return 0;
}
