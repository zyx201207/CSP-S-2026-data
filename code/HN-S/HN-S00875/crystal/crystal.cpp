#include<bits/stdc++.h>
using namespace std;
long long n , m , a[500005] , ans[500005];
bool s = false;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1; i <= n ; i++){
		cin >> a[i];
	}
	for(long long i = 2; i <= n ; i++){
		if(a[i - 1] == a[i]) s = true;
		else{
			s = false;
			break;
		}
	}
	if(s == true){
		cout << n;
		return 0;
	}else{
		sort(a+1,a+n+1);
		for(long long i = 1; i <= n; i++){
			long long b = a[i];
			long long c = m;
			for(long long j = 1; j <= n; j++){
				if(abs(a[j] - b) <= c){
					c -= abs(a[j] - b);
					ans[i] += 1;
				}
			}
		}
		sort(ans + 1 , ans + n + 1);
		cout << ans[n];
		return 0;
	}
	return 0;
} 
