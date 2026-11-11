#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	long long ans = a[n];
	for(long long i = n - 1;i > (n - m);i--){
		ans = a[i] & ans;
	}
	cout << ans; 
	return 0;
}
