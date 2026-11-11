#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n,m,a[N],sum[N],pyc;
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;++i) cin >> a[i];
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;++i) sum[i] = sum[i - 1] + a[i];
	for(int l = 1,r = 1;r <= n;++r){
		while(l < r && a[r] * (r - l + 1) - (sum[r] - sum[l - 1]) > m) ++l;
		pyc = max(pyc,r - l + 1);
	}cout << pyc << "\n";
	return 0;
}