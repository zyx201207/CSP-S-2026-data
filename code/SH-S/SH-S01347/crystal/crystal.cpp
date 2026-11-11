#include<bits/stdc++.h>
#include<cstdio>
const int N = 5e5+10;
using namespace std;
int n, ans, p[N];
long long m;
long long a[N], sum[N], f[N];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; ++i) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i=1; i<=n; ++i){
		sum[i] = sum[i-1]+a[i];
		f[i] = a[i]*i-sum[i];
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=i; ++j){
			if(f[i]-f[j-1]<=m){
				ans = max(ans, i-j+1);
				break;	
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
