#include<bits/stdc++.h>
#define int long long
#define pic pair<int, char>
#define fir first
#define sec second
using namespace std;
const int N = 100010;
int n, ans;
pic a[200010];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i].fir >> a[i].sec;
	}
	int l = 1, r = n, cl = 0, cr = 0;
	while(l < r){
		int minn = min(a[l].fir, a[r].fir);
		ans += minn * (int)(a[l].sec != a[r].sec);
		a[l].fir -= minn;
		a[r].fir -= minn;
		l += (!a[l].fir);
		r -= (!a[r].fir);
	}
	cout << ans;
	return 0;
}
//Ë«Ö¸Õë100pts
//checked 
//O(n)
