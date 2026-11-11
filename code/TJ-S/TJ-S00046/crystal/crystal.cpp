#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500005],m,ans,b[500005];
bool f = true,ff = true;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != i) f = false;
	}
	sort(a + 1,a + 1 + n);
	if(f){
		int sum = 0;
		for(int i = 1;i <= n;i++) {
			sum += i;
			b[i + 1] = sum;
		}
		for(int i = 2;i <= n;i++){
			if(b[i] <= m) ans++;
		}
		cout << ans << "\n";
		return 0;
	}
	int x = a[2] - a[1];
	for(int i = 3;i <= n;i++){
		if(a[i] - a[i - 1] != x) ff = false;
	}
	if(ff){
		int sum = 0;
		int anss = 1;
		for(int i = 1;i <= n;i++){
			sum += (a[i - 1] + x);
			//cout << sum << " ";
			if(sum <= m) anss++;
		}
		cout << anss << "\n";
		return 0;
	}
	for(int i = 2;i <= n;i++){
		int num = 0;
		for(int j = 1;j < i;j++){
			//if(a[j] == a[j - 1]) ans++;
			num += a[i] - a[j];
		}
		if(num <= m) ans = i;
		//anss = max(ans,anss);
	}
	cout << ans << "\n";
	return 0;
}
