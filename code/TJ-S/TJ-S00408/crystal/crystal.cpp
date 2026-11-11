#include<bits/stdc++.h>
using namespace std;

long long n , m , ans = 1;
long long a[500005];
long long s[500005];

long long find(long long x){
	long long l = 1 , r = x , num;
	while(l <= r){
		long long mid = (l + r) / 2;
		if((x-mid+1)*a[x] - (s[x]-s[mid-1]) <= m){
			num = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	return num;
}

int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	
	cin >> n >> m;
	
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
	}
	
	sort(a+1 , a+n+1);
	
	for(long long i = 1;i <= n;i++){
		s[i] = s[i-1] + a[i];
	}
	
	for(long long i = 2;i <= n;i++){
		long long x = find(i);
		ans = max(ans , i-x+1);
	}
	cout<<ans;
	return 0; 
} 
