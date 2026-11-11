#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int N=5e5+15;
int a[N], ans=1;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n,m,cnt=1; cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+n+1); int k=m, h=1;
	for(int i=2; i<=n; i++){
		cnt++; k-=(a[i]-a[i-1])*(i-h);
		while(k<0){
			cnt--;
			k+=(a[i]-a[h]); h++;
		}
		ans=max(ans, cnt);
	}
	cout << ans;
	return 0;
} 
