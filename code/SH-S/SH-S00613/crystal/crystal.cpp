#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 +10;
int n;
long long m;
long long a[N] = {};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1, a+1+n);
	if(a[1] < 0) for(int i = n;i>=1;i--) a[i] -= a[1];
	int l = 1, r = 2;
	int ans = -1010000000;
	while(l < r && r <= n+1){
		cout<<l<<' '<<r<<' '<<a[r]-a[l-1]<<' '<<a[r-1]-a[l-1]<<'\n';
		if(a[r]-a[l-1] > m && a[r-1]-a[l-1] <= m){
			ans = max(ans, r-l);
		}
		if(a[r]-a[l-1] > m){
			l++;
		}else r++;
	}
	cout<<ans;
	return 0;
}
