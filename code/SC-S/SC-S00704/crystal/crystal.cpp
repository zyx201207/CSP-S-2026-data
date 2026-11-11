#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int MAXN = 5e5 + 5;
int n,ans;
ll a[MAXN],m,sum[MAXN];
ll query(int i,int k){
	return (i-k+1)*a[i] - (sum[i] - sum[k-1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 1;i<=n;i++) sum[i] = sum[i-1] + a[i];
	for (int k = 1;k<=n;k++){
		int l = k,r = n;
		while (l < r){
			int mid = (l+r)/2;
			if (query(mid,k) <= m){
				l = mid + 1;
			}
			else{
				r = mid;
			}
		}
		ans = max(ans,((l-1)-k+1));
	}
	cout << ans;
}