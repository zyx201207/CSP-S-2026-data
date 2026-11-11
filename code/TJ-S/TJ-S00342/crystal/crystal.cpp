#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, l, r, m, ans;
ll arr[500005];
ll s[500005];

bool check(int len){
	for(int L=1; L<=n-len+1; L++){
		int R=L+len-1;
		int cost = s[R]-s[L-1]-(L-1)*(arr[R]-arr[L-1]);
		
		if(cost <= m){
			return true;
		}
	}
	
	return false;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	l=1, r=n;
	
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	
	sort(arr+1, arr+n+1);
	
	for(int i=1; i<=n; i++){
		s[i] = s[i-1]+(arr[i]-arr[i-1])*(i-1);
	}
	
	while(l<=r){
		ll mid = (l+r)>>1;
		
		if(check(mid)){
			ans = mid;
			l = mid+1;
		} 
		else{
			r = mid-1;
		}
	}
	
	cout<<ans;
	
	return 0;
}
