#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5+10;
int n, m, res = 0;
int a[maxn], pre[maxn];

bool check(int st, int len){
	int cost = a[st]*len - (pre[st-1]-pre[st-len-1]);
	//cout << st << " " << len << " " << cost << endl;
	return cost <= m;
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	
	for(int i =1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i =1;i<=n;i++){
		int l = 0, r=i-1;
		int ans = -1;
		while(l<=r){
			int mid = (r-l)/2+l;
			if(check(i, mid)){
				ans = mid;
				l = mid+1;
			} else r = mid-1;
		}
		//cout << ans+1<<endl;
		res = max(res, ans+1);
	}                        

	cout << res;
}

