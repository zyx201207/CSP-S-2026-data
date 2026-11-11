#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
typedef long long ll;
ll a[N], egy[N];
ll n, m;
int fnd(int x, int l, int r){
	int mid;
	while(l <= r){
		mid = (l + r) >> 1;
		if((a[x] - a[mid]) * mid + egy[mid - 1] > egy[x] - m)	r = mid - 1;
		else l = mid + 1;
	}
	return l;
}
int ans;
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++)  cin >> a[i];
    sort(a, a + n);
    for(int i = 1; i < n; i++){
        egy[i] = (a[i] - a[i - 1]) * i + egy[i - 1];
        if(egy[i] <= m) ans = max(ans, i + 1);
        else{
			if(i - ans < 0) continue;
			int tmp = fnd(i, 0, i);
            ans = max(ans, i - tmp + 1);
        }
    }
    cout << ans;
    return 0;
}