#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
long long m,a[N],s[N];//i代表1~i的和 
int l,r,n;
long long check(int x){
	long long cost = 1e18;
	for(int i = x;i<=n;++i){
		cost = min(cost,x*a[i]-(s[i+1]-s[i-x+1]));
	}
	return cost;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;++i){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	r=n;
	for(int i = 1;i<=n;++i){
		s[i] = s[i-1] + a[i-1];
	}
	while(l<r){
		int mid = (l+r)/2;
		if(check(mid)<=m){
			l = mid+1;
		}
		else{
			r = mid;
		}
	}
	cout << --l;
} 
