#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	ll l=1, r=1,tl=1,tr=0;
	sort(a+1, a+1+n);
	if(m>=2*(a[n]-a[1])){
		cout<<n;
		return 0;
	}
	bool v=1;
	for(int i = 1; i <= n; i++){
		if(a[i+1] == a[i]) r++;
		else{
			if(tr < r || v ){
				tl = l;
				tr = r;
				v = false;
			}
			l += r;
			r = 1;
		}
	}
	ll mid;
	if(tr == 1) mid = int((n+1)/2);
	else mid = tl;
	ll ans = 0, u=mid-1,tmp=0,flag;
	while(1){
		tmp+=(a[mid]-a[u--]);
		if(tmp > m) break;
		else if(tmp == m) {
			ans++;
			break;
		}
		ans++;
	}

	cout<<ans+tr;
	return 0; 
}