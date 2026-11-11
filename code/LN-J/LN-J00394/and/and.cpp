#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N=2e5+10;
ll a[N];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	
	if(m==1){
		sort(a+1, a+1+n);
		cout << a[n] << endl;
		return 0;
	}
	
	if(m==n){
		ll ans=0;
		for(int i=1; i<=n; i++)
		    ans=ans & a[i];
		cout << ans << endl;
		return 0;
	}
	
	if(m==2){
		ll ans=0;
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				ans=max(ans, a[i] & a[j]);
			}
		}
		cout << ans << endl;
		return 0;
	}
	
	return 0;
}
