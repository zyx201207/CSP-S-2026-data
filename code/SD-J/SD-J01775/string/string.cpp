#include <bits/stdc++.h>
using namespace std;

long long n , ans=0;
long long a[200005];
char c[200005];

long long l , r;

void xxl(){

	if(c[l] == c[r]){
		if(a[l] > a[r]){
			a[l] -= a[r];
			r--;
		}
		else if(a[l] == a[r]){
			l++;
			r--;
		}
		else{
			a[r] -= a[l];
			l++;
		}
	}
	else{
		if(a[l] > a[r]){
			ans += a[r];
			a[l] -= a[r];
			r--;
		}
		else if(a[l] == a[r]){
			ans += a[r];
			l++;
			r--;
		}
		else{
			ans += a[l];
			a[r] -= a[l];
			l++;
		}
	}
}

int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(long long i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	
	l = 1;
	r = n;
	
	while(l < r){
		xxl();
	}
	
	cout << ans;
	return 0;
} 
