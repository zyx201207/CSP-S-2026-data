#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],ans,anss = -1;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		ans = a[i];
		int num = 1;
		for(int j = i + 1;j <= n;j++){
			if(num == m or n - i - 1 < m) break;
			ans &= a[j];
			num++;
		}
		anss = max(ans,anss);
	}
	cout << anss << "\n";
	return 0;
}
