#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, t, ans, z;
const int N = 5e5+10;
ll a[N], c[N], zz[N];
ll s, s1, s2, s3, s4, s5;
int main(){
	freopen("crstal.in","r",stdin);
	freopen("crstal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	ll s = 1;
	s2 = 1;
	for(ll i = 2; i <= n; i++){
		if(a[i] == t){
						s++;
						s2 = max(s, s2);
					} 
		else{
			s2 = max(s, s2);
			t = a[i];
			s = 1;
			}
	}
	if(s2 > 1){
				s3 = s2;
				s4 = s2;
				c[1] = a[1];
				for(int i = 1; i <= n; i++){
					c[i] = a[i]-a[i-1];
				}
				t = 0;
				for(int i = 1; i <= n; i++){
					if(c[i] == 0){
					t++;
					zz[t] = i;
					}
				}
				for(int i = 1; i <= t; i++){
					z = m;
					s3 = s2;
					s4 = s2;
					for(int j = c[i]+1; j <= n; j++){
						z -= (a[j]-a[c[i]]);
						if(z < 0){
									s3 += j-c[i]-1;
									break;
								}
					}
					z = m;
					for(int j = 1; j <= c[i]-s2+1; j++){
						z -= (a[c[i]]-a[j]);
						if(z < 0){
									s4 += c[i]-j-1;	
									break;
									}
					}
					s5 = max(s3, s4);
				}
			}
			
			
			
			
	ll l = a[1];
	ll r = a[n];
	while(l < r){
		ll mid = (l+r)/2;
		ll z = m;
		for(ll i = 1; i <= n; i++){
			z -= (mid-a[i]);
			if(a[i] >= mid){
							
							break;
							}
			if(z <= 0){
					r = mid;
					break;	
					}
		}
		if(z > 0){
					l = mid+1;
					}
	}
	for(int i = 1; i <= n; i++){
		if(a[i] <= l) a[i] = l;
	}
	ll s1 = 1;
	s = 1;
	ll t = a[1];
	for(int i = 2; i <= n; i++){
		if(a[i] == t){
						s++;
						s1 = max(s, s1);
					} 
		else{
			s1 = max(s, s1);
			t = a[i];
			s = 1;
			}
	}
	ll ans = max(s5, s1);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
