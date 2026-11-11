//Œ“ «…X…m 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
struct llll{
	ll t;
	char c;
}a[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(ll i = 1;i <= n;i++){
		cin >> a[i].t >> a[i].c;
	}
	ll ans = 0;
	ll l = 1,r = n;
	while(l < r){
		if(a[l].c != a[r].c){
			if(a[l].t < a[r].t){
				a[r].t -= a[l].t;
				ans += a[l].t;
				l++;
			}else if(a[l].t > a[r].t){
				a[l].t -= a[r].t;
				ans += a[r].t;
				r--;
			}else{
				ans += min(a[l].t,a[r].t);
				l++;
				r--;
			}
		}else{
			if(a[l].t < a[r].t){
				a[r].t -= a[l].t;
				l++;
			}else if(a[l].t > a[r].t){
				a[l].t -= a[r].t;
				r--;
			}else{
				l++;
				r--;
			}
		}
//		for(ll i = 1;i <= n;i++){
//		cout<< a[i].t <<" "<< a[i].c<< endl;;
//	}
	}
	cout << ans;
	return 0;
}
