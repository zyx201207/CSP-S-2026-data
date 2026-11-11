#include <bits/stdc++.h>
using namespace std;
long long a[20000005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i = 0; i<n; i++) cin >> a[i];
	sort(a,a+n,cmp);
	//for(int i = 0; i<n; i++) cout << a[i] << " ";
	long long ans = a[0];
	for(int i = 0; i<m; i++) {
		ans = (ans & a[i]);
		//cout << ans << " ";
	}
	cout << ans;
//cout << (262143 & 262142);
	return 0;
} 
