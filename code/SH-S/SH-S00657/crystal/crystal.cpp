#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500009],sum[500009];
void solvebf(){
	sort(a,a+n);
	for(int i=0; i<n-1; i++){
		sum[i] = a[i+1]-a[i];
	}
	ll ans = -1;
	for(int i=0; i<n; i++){
		ll p = m;
		ll num = 1;
		ll s = 1;
		for(int j=i; j<n-1; j++,s++){
			if(p >= sum[j]*s){
				p-=sum[j]*s;
				num++;
			}else{
				break;
			}
		}
		if(num > ans){
			ans = num;
		}
	}
	cout << ans << endl;
}
void solvep1(){
	int base = 1;
	int res = 1;
	while(m >= base){
		m -= base;
		base++;
		res++;
	}
	cout << res << endl;
}
void solveps(int re){
	int base = 1;
	int res = 1;
	while(m >= base*re){
		m -= base*re;
		base++;
		res++;
	}
	cout << res << endl;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool plus1 = true,psame = true;
	for(int i=0; i<n; i++){
		cin >> a[i];
		if(a[i] != i+1){
			plus1 = false;
		}
	}
	ll same = a[1]-a[0];
	for(int i=1; i<n; i++){
		if(a[i]-a[i-1] != same){
			psame = false;
		}
	}
	if(n<=5000){
		solvebf();
	}else if(plus1){
		solvep1();
	}else if(psame){
		solveps(same);
	}
	return 0;
}

