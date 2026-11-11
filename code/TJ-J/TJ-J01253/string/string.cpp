#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MX = 2e5+5;
ll T;
ll ans;

ll n[MX]; 
char c[MX];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int i=0;i<T;i++){
		cin >> n[i] >> c[i];
	}
	ll l=0,r=T-1,la,ra,lc,rc;
	while(l<r){
		la = n[l]; lc = c[l];
		ra = n[r]; rc = c[r];
		if(la>ra){
			if(lc!=rc){
				ans+=ra;}
			n[l] = la-ra;
			r--;
		}else{
			if(lc!=rc){
				ans+=la;}
			n[r] = ra-la;
			l++;
		}
	}
	cout << ans;
	return 0; 
} 
*/
