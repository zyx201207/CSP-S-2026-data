#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
long long n, m;
long long cry[N], q[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> cry[i];
	}
	sort(cry + 1, cry + n + 1);
	for(int i = 1; i <= n; i++){
		q[i] = q[i - 1] + cry[i];
	}
	long long ans = 1;
	for(int i = 2; i <= n; i++){
		//long long k = m;
		long long l = 1, r = i, mid;
		while(l <= r){
			mid =(l + r)/2;
			if(cry[i] * mid - (q[i - 1] - q[i - 1 - mid]) <= m){
				l = mid + 1;
			}
			else{
				r = mid - 1;
				
			}
		}
		
		
		if(l >= ans){
			//cout << i << " " << mid << endl;
			ans = l; 
		}
		
	}
	
	cout << ans;
	
	return 0;
} 
