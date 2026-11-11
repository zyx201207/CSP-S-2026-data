#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(void){
	ifstream fin("crystal.in", ios_base::in);
	ofstream fout("crystal.out", ios_base::out);
	ll n;
	unsigned ll m;
	fin >> n >> m;
	vector<ll> a(n, 0);
	for(int i=0;i<n;i++) fin >> a[i];
	sort(a.begin(), a.end());
	for(int i=0;i<n;i++) a[i] -= a[n - 1];
	ll ans = 0;
	for(int i=0;i<n;i++){
		ll l = i - 1, r = i + 1, c = 1;
		unsigned ll p = m;
		while(p > 0 && !(l < 0 && r >= n)){
			if(l < 0){
				if(p >= (a[r] - a[i]) * (i - l - 1)) p -= (a[r++] - a[i++]) * (i - l - 1), c++;
				else break;
			}
			else if(r >= n){
				if(p >= a[i] - a[l]) p -= a[i] - a[l--], c++;
				else break;
			}
			else{
				if(a[i] - a[l] <= (a[r] - a[i]) * (i - l - 1)){
					if(p >= a[i] - a[l]) p -= a[i] - a[l--], c++;
					else break;
				} else {
					if(p >= (a[r] - a[i]) * (i - l - 1)) p -= (a[r++] - a[i++]) * (i - l - 1), c++;
					else break;
				}
			}
		}
		ans = max(ans, c);
	}
	fout << ans;
	return 0;
}
