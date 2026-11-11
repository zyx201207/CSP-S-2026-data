#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
int n,l,r,ans;
long long m,a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	ans = 1;
	l = 1;
	for(int i = 2;i <= n;i++){
		r = i;
		m -= (r - l) * (a[r] - a[r-1]);
		while(m < 0){
			m += a[r] - a[l];
			l++;
		}
		ans = max(ans,r-l+1);
	}
	cout << ans;
	return 0;
}
