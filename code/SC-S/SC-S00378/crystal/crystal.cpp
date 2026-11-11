#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+3;
int n,a[N],st[N],sm[N],m,ans;
bool check(int i,int x){  // [x .. i] 全部合成可不可以
 	return (i-x+1)*a[i]-(sm[i]-sm[x-1]) <= m; 
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		sm[i] = sm[i-1]+a[i];   //前缀和应该用排序过后的！
	}
	for(int i=1;i<=n;++i){
		int l = 1,r = i;
		while(l < r){
			int mid = (l+r)/2;
			if(check(i,mid)) r = mid;
			else l = mid+1;
		}
		ans = max(ans,i-r+1);
	}
	cout << ans << "\n";
	return 0;
}