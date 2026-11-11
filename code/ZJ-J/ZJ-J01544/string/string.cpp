#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

int n;
ll a[N];
char ch[N];
ll ans = 0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> ch[i];
	}
	
	int l = 1,r = n;
	while(l < r){
		ll cnt = 0;
		if(a[l] == a[r]){
			if(ch[l] != ch[r]) cnt += a[l]; 
		}
		else if(a[l] < a[r]){
			if(ch[l] != ch[r]) cnt += a[l];
			
			ll k = a[l];
			while(l < r){
				l++;
				if(a[r] - k >= a[l]){
					if(ch[l] != ch[r]) cnt += a[l];
					k += a[l];
				}
				else{
					if(ch[l] != ch[r]) cnt += (a[r] - k);
					a[l] -= (a[r] - k);
					l--;
					break;
				}
			}
		}
		else if(a[l] > a[r]){
			if(ch[l] != ch[r]) cnt += a[r];
			
			ll k = a[r];
			while(l < r){
				r--;
				if(a[l] - k >= a[r]){
					if(ch[l] != ch[r]) cnt += a[r];
					k += a[r];
				}
				else{
					if(ch[l] != ch[r]) cnt += (a[l] - k);
					a[r] -= (a[l] - k);
					r++;
					break;
				}
			}
		}
		
		ans += cnt;
		l++;
		r--;
	}
	
	cout << ans;
	
	return 0;
}
