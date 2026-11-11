#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
ll m;
ll a[N],s[N];
int ans,n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
//		cout << 1 << endl;
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i ++)s[i] = s[i - 1] + a[i];
	for(int i = 1;i <= n;i ++){
		if(m - i * a[i] + s[i] >= 0)ans = max(ans,i);
	}
//	cout << ans << endl;
	for(int i = n;i >= 1;i --){
		if(m >= (n - i + 1) * a[n] - s[n] + s[i - 1]){
			ans = max(ans,n - i + 1);
		}
	}
//	cout << ans << endl;
	int l = 1,r = l + ans;
	while(r <= n){
		if(ans * a[r] - s[r - 1] + s[l - 1] > m)l ++;
		else ans ++;
		r = l + ans;
	}
	cout << ans;
	return 0;
} 
//11 10 1 2 3 7 8 9 10 11 17 18 19
