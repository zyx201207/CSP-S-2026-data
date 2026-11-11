#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N];
int pre[N];

int n, m;
int ans;

bool check(int x, int ft){
	int nd;
	nd = pre[x] - pre[ft];
	nd -= (a[x] - a[ft]) * (ft - 1ll);
	
	if (m >= nd) return true;
	else		 return false; 
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%lld%lld", &n, &m);	
	
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	
	sort(a + 1, a + 1 + n);
	
	for (int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + (a[i] - a[i - 1ll]) * (i - 1ll);
	}
	
	for (int i = 1; i <= n; i++){
		int l = i, r = n;
		
		while(l < r){
			int mid = (l + r + 1ll) >> 1;
			
			if (check(mid, i)) l = mid;
			else			   r = mid - 1ll;
		}
		
		ans = max(ans, l - i + 1);
	}
	
	printf("%lld", ans);	
		
	return 0;
}