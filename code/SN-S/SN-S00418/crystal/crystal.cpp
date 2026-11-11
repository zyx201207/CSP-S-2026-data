#include <bits/stdc++.h>
#define int long long
#define maxn 500010
using namespace std;
int n,m;
int a[maxn];
int s[maxn];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	int mn = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		mn = min(mn,a[i]);
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		a[i] -= mn;
	}
	for(int i = 1;i <= n;i++){
		s[i] = s[i - 1] + a[i];
//		cout << s[i] << " ";
	}
//	cout << endl;
	int l = 1,ans = 0;
	for(int i = 1;i <= n;i++){
		while(l <= i && a[i] * (i - l + 1) - s[i] + s[l - 1] > m){
			l++;
		}
		ans = max(ans,i - l + 1);
	}
	cout << ans << endl;
}
