#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[500005],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		int sum=0,cnt=1;
		for(int j = i-1;j >= 1;j--){
			sum += a[i]-a[j];
			if(sum > m) break;
			cnt++;
		}
		ans = max(ans,cnt); 
	}
	cout << ans;
	return 0;
}
