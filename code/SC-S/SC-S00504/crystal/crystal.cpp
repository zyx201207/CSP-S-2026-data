#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mid (l+r)/2
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	vector<int> acc(n+1);
	for(int i = 0; i < n; i++){
		acc[i+1] = acc[i] + a[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		int l = 0;
		int r  =i+2;
		while(r-l > 1){
			if((mid * a[i] - (acc[i+1] - acc[i+1-mid] )) <= m){
				l = mid;
			}
			else{
				r = mid;
			}
		}
		ans = max(ans,l);
	}
	cout<<ans;
}