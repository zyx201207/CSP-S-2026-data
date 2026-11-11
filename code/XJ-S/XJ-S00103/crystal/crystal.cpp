#include <bits/stdc++.h>
#include <vector>
#include <algorithm> 
using namespace std;
typedef long long ll;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll m;
	if(!(cin >> n >> m)) return 0;
	vector<ll> a(n+1);
	for(int i = 1;i<=n;i++) cin >>a[i];
	sort(a.begin()+1,a.end());
	vector<ll> pref (n+1,0);
	for(int i = 1;i<=n;i++){
		pref[i] = pref[i-1] + a[i]; 
	}
	int l =1,r=n,ans=1;
	while(l<=r){
		int mid=l+(r-l)/2;
		bool ok = false;
		for(int i =mid ; i<= n;i++){
			ll cost= (ll)mid*a[i]-(pref[i]-pref[i-mid]);
			if(cost<=m){
				ok = true;
				break;
			}
		}
		if(ok){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout << ans << "\n";
	return 0;	
}
