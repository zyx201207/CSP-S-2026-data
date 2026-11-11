#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n , m;
long long a[N];
bool check(long long x){
	for(int i = x ; i<=n ; i++){ 
		int cur = 0;
		long long cnt = x-1;
		for(int j = i-1 ; j>=i-x+1 ; j-- , cnt--){
			cur+=1LL*cnt*(a[j+1]-a[j]);
			if(cur>m){
				break;
			}
		}
		if(cur<=m){
			return 1;
		}
	} 
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool flag = 1;
	for(int i = 1 ; i<=n ; i++){
		cin>>a[i];
	}
	int d = a[2]-a[1];
	for(int i = 3 ; i<=n ; i++){
		if(a[i]-a[i-1]!=d){
			flag = 0;
			break;
		}
	}
	if(flag){
		int ans = 0;
		for(int i = 1 ; i<=n ; i++){
			if(ans+d>m) break;
			ans++;
			d+=d;
		}
		cout<<ans+1<<'\n';
		return 0;
	}
	sort(a+1,a+n+1);
	int l = 0 , r = n+1;
	while(l<r){
		int mid = (r+l)/2;
		if(check(mid)){
			l = mid+1;
		}
		else{
			r = mid;
		}
	}
	cout<<l-1<<'\n';
	return 0;
}

