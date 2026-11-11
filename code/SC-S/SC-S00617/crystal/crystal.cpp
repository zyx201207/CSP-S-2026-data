#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
#define int long long
int a[N],b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin >> n >> m;
	bool flagS = true;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		b[i] = b[i-1]+a[i];
		if(i > 2 && a[i]-a[i-1] != a[i-1]-a[i-2]) flagS = false;
	}
	sort(a,a+n);
	int maxn = 0;
	if(flagS){
		int ans = n;
		for(int j = 1;j <= n;j++){
			int sum = (a[j]*(j-1))-(b[j-1]);
			if(sum > m){
				ans = j-1;
				break;
			}
		}
		cout << ans;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		int ans = n-i+1;
		for(int j = i;j <= n;j++){
			int sum = (a[j]*(j-i))-(b[j-1]-b[i-1]);
			if(sum > m){
				ans = j-i;
				break;
			}
		}
		maxn = max(maxn,ans);
	}
	cout << maxn;
	return 0;
}