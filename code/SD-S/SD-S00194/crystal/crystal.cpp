#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long m,a[N],sum[N];
int n,l,r,mid,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = n;i > 0;i--){
		l = 1;
		r = i;
		while(l < r){
			mid = (l + r) >> 1;
			if(a[i] * (long long)(i - mid + 1) - (sum[i] - sum[mid - 1]) <= m){
				r = mid;
			}else{
				l = mid + 1;
			}
		}
		ans = max(ans,i - l + 1);
	}
	cout << ans;
	return 0;
}
