#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 5;
int n,m,a[MAXN],b[MAXN];
bool cmp(int a,int b){
	return a > b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;++i) cin >> a[i];
	sort(a + 1,a + n + 1,cmp);
	
	if(m == n){
		int maxn = pow(2,31) - 1;
		for(int i = 1;i <= n;++i) {
			maxn &= a[i];
			cout << maxn;
		}
		cout << maxn;
		return 0;
	}
	if(m == 1){
		sort(a + 1,a + n + 1);
		cout << a[n];
		return 0;
	}
	if(a[n] <= 4){
		cout << a[m];
		return 0;
	}
	int maxn = -1,l,k;
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= n;++j){
			if(i == j) continue;
			if(a[i] & a[j] > maxn) maxn = a[i] & a[j];
		}
	}
	cout << maxn;
	return 0;
}
