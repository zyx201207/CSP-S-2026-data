#include <bits/stdc++.h>
using namespace std;

// Oct31==Dec25?

#define int long long


int n,m;
const int N = 5e5 + 100;
int a[N];
int b[N];
int k;

bool check(int x){
	int sum = (k - x + 1) * a[k] - (b[k] - b[x-1]);
	return sum <= m;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)
		b[i] = b[i-1] + a[i];
	
	int ans = 0;
	for(int i = 1;i <= n;i++){
		k = i;
		int l = 0,r = i;
		while(l + 1 < r){
			int m = (l + r) / 2;
			if(check(m))
				r = m;
			else
				l = m;
		}
		ans = max(ans,i - r + 1);
	}
	cout << ans << '\n';
	return 0;
}
