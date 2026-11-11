#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],s[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++) s[i] = s[i-1] + a[i];
	int ans = 1;
	for (int i = 2;i <= n;i++){
		int l = 1,r = i-1,mid = (l+r) / 2;
		while (l <= r){
			mid = (l+r) / 2;
			if (a[i] * (i - mid) - (s[i-1] - s[mid-1]) <= m) r = mid - 1;
			else l = mid + 1;
		}
		if (a[i] * (i - mid) - (s[i-1] - s[mid-1]) <= m) ans = max(ans,i-mid+1);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}