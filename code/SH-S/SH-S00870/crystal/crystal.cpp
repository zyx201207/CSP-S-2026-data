#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N];
long long n,m;
bool ISTESHUXINGZHIA = 1,ISTESHUXINGZHIB = 1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i]!=i){
			ISTESHUXINGZHIA = 0;
		}
		if(i >= 3 && a[i]-a[i-1]!=a[i-1]-a[i-2]){
			ISTESHUXINGZHIB = 0;
		}
	}
	if(ISTESHUXINGZHIA){
		long long i = 1;
		for(;;i++){
			if(m-i < 0){
				break;
			}
			m -= i;
		}
		cout << i + 1;
		return 0;
	}
	if(ISTESHUXINGZHIB){
		long long diff = a[2]-a[1];
		long long i = 1;
		for(;;i++){
			if(m-i*diff < 0){
				break;
			}
			m -= i*diff;
		}
		cout << i + 1;
		return 0;
	}
	sort(a+1,a+n+1);
	long long maxx = 0;
	for(long long i = 1;i <= n;i++){
		long long tmp = m;
		long long ans = 0;
		for(long long j = i;j >= 1;j--){
			if(tmp-(a[i]-a[j]) < 0){
				break;
			}
			ans ++;
			tmp -= a[i]-a[j];
		}
		maxx = max(maxx,ans);
	}
	cout << maxx;
	return 0;
} 
