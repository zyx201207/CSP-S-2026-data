#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, x, zz, ans;
struct node{
	int c;
	string zzz;
}a[200005];
string s, z;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;//scanf("%lld", &n);
	if(n <= 100000){
		s = "";
		for(ll i = 1; i <= n; i++){
			cin >> x >> z;//scanf("%lld%d", &x, &z);
			for(ll j = 1; j <= x; j++){
				s += z;
			}
		}
		for(ll i = 0; i < s.size()/2; i++){
				if(s[i] == s[s.size()-1-i]){
										continue;
										} 
				else ans++;
		}
		cout << ans;//printf("%d", ans);
	}
	else{
		s = "";
		for(ll i = 1; i <= n; i++){
			cin >>a[i].c >> a[i].z;
			zz += a[i].c;//scanf("%lld%d", &x, &z);
		}
		ll l = 1, r = n;
		while(l <= r){
			if(a[l].zzz==a[r].zzz){
								if(a[l].c > a[r].c){
													a[l].c -= a[r].c;
													r -= 1;
													} 
								else {
									a[r].c -= a[l].c;
									l += 1;
									}
								}
			else{
				ans += min(a[r].c, a[l].c);
				if(a[l].c > a[r].c){
									r -= 1;
									} 
								else {
									l += 1;
									}
			}
		}
		cout << ans;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
