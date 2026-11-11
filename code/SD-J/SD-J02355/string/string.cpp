#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 5;
LL ans, A[N], t;
char C[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	LL n;
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> A[i] >> C[i];
	}
	LL l = 1, r = n;
	while(l < r){
		while(A[l]){
			if(C[r] != C[l]) ans += min(A[l], A[r]);
			t = A[l];
			A[l] = max(A[l] - A[r], LL(0));
			A[r] = max(A[r] - t, LL(0));
			if(A[r] == 0) r --;
			if(r == l) break;
		}
		l ++;
	}
	cout << ans;
	return 0;
}

