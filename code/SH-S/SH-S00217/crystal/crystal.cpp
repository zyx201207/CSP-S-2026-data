#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],cf[500005],qz[500005],ans = -1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
		cin >> a[i];
	sort(a + 1,a + 1 + n);
	for(int i = 2;i <= n;i ++)
		cf[i] = a[i] - a[i - 1];
	for(int i = 2;i <= n;i ++)
		cf[i] += cf[i - 1],qz[i] = qz[i - 1] + cf[i];
	for(int i = 2;i <= n;i ++){
		int l = 1,r = i;
		while(l < r){
			int mid = (l + r) >> 1;
			if((i - mid + 1) * cf[i] - qz[i] + qz[mid - 1] <= m){
				r = mid;
				ans = max(ans,i - mid + 1);
			}
			else l = mid + 1;
		}
		
	}
	cout << ans;
	return 0;
} 
