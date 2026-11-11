#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 200010;
ll n,v[N],len,vl,vr;
char a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(ll i = 1 ; i <= n ; i++){
		cin >> v[i] >> a[i];
		len += v[i];
	}
	vl = len/2,vr = len-vl+1;
	ll l = 1,ml = 0,r = n,mr = len,ans = 0;
	while(ml <= vl && mr >= vr){
		if(l == r) break;
		if(a[l] == a[r]){
			if(v[l] < v[r]){
				v[r] -= v[l];
				mr -= v[l];
				ml += v[l++];	
			} else {
				v[l] -= v[r];
				ml += v[r];
				mr -= v[r--];
			}
		} else if(v[l] < v[r]){
			ans += v[l];
			v[r] -= v[l];
			mr -= v[l];
			ml += v[l++];
		} else {
			ans += v[r];
			v[l] -= v[r];
			ml += v[r];
			mr -= v[r--];
		}
	}
	cout << ans << endl;
	return 0;
}
