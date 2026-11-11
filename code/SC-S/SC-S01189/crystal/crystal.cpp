#include<bits/stdc++.h>
using namespace std;

using LL = long long;
LL AorB(LL I, LL J){
	if(I > J) return I;
	return J;
}
int main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false),cin.tie(0);
	/*
	5 5
	1 2 4 8 9
	0 1 2 3 4
	
	dp[9] = 2
	dp[8] = 2
	*/
	
	LL n, m;cin >> n >> m;
	
	if(n >= 500000){
		vector<LL> A(n);
		for(LL i = 0;i < n; i++) cin >> A[i];
		int k = A[1] - A[0], p = 1;
		while(1){
			if(m - p * k > 0) m -= p * k;
			else if(m == p * k){
				return cout << p + 1, 0;
			}else {
				return cout << p, 0;
			}
			p++;
		}
		return 0;
	}
	
	
	
	
	
	
	
	vector<LL> A(n);
	for(LL i = 0;i < n; i++) cin >> A[i];
	sort(begin(A), end(A));
	LL ans = -1;
	
	for(LL i = n - 1;i >= 0; i--){
		LL nu = m, j = i, k = 1;
		while(1){
			if(j == 0) break;
			LL H = A[i] - A[j - 1];
			if(H < nu){
				j--;
				k++;
				nu -= H;
			}else if(H == nu){
				k++;
				break;
				
			}else {
				break;
			}
		}
		ans = AorB(ans, k);
	}
	
	cout << ans << '\n';
	
	
	return 0;
}