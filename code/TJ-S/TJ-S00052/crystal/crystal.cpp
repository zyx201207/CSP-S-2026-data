#include <bits/stdc++.h>
#define int long long
#define i32 signed
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
//bu ke yi zong si ling (/TAT)/
int n,m,a[500005],maxx = 1;
using namespace std;
bool cmp(int a,int b){
	return a <= b;
}
bool A(){
	for(int i = 1;i <= n;i++){
		if(a[i] != i){
			return 0;
		}
	}
	return 1;
}
i32 main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	int v = m;
	if(A){
		for(int i = 2;i <= n;i++){
			if(m * 2 >= i * i - i){
				maxx = i;
			}
		}
	}
	else {
		rep(i,2,n){
			int ans = 1;
			if(a[i + 1] == a[i]){
				continue;
			}
			per(j,i - 1,1){
				m += a[j];
				m -= a[i];
				if(m >= 0){
					ans++;
				}
				else {
					break;
				}
			}
			if(ans > maxx){
				maxx = ans;
			}
			if(ans < maxx){
				break;
			}
			m = v;
		}
	}
	cout << maxx;
	return 0; 
}

