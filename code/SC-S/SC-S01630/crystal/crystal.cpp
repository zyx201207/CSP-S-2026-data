#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[500005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1, greater<int>());
	int cnt=1;
	for(int i=2; i<=n; i++){
		int k=a[1]-a[i];
		if(m-k>=0){
			a[i]+=k;
			m-=k;
			cnt++;
		}else{
			break;
		}
	}
	cout << cnt;
	return 0;
}