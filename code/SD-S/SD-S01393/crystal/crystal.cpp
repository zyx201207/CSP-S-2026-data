#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,ans = 0;
ll A[1000001],B[1000001];
ll er(ll l,ll r,ll i){
	ll mid;
	while(l <= r){
//		cout << i << endl;
		mid=(l+r)/2;
		if(A[i]*mid-B[i]+B[i-mid]<=m){
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	ans = max(ans,mid);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(ll i = 1;i <= n;i++){
		cin >> A[i];
	}
	sort(A+1,A+1+n);
	for(ll i = 1;i <= n;i++){
		B[i] = B[i-1]+A[i]; 
	}
	for(ll i = 1;i <= n;i++){
		er(1,i,i);
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
Oct31==Dec25?

1 2 4 8 9
4 4 4 8 9
2 2 4 8 9
8 8 8 8 9
9 9 9 9 9

*/ 

