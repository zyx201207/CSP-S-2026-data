#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	int l = 1,sum = 0;
	int ans = 1;
	for(int i = 2;i <= n;i++){
		while((i-l)*(a[i]-a[i-1])+sum > m) sum -= a[i-1]-a[l],l++;
		sum += (i-l)*(a[i]-a[i-1]);
		ans = max(ans,i-l+1);
//		cout << l << " " << i << "\n";
	}
	cout << ans;
}
