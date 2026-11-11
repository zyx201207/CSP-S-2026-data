#include <bits/stdc++.h>
using namespace std;
long long n;
string b,qw;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long sum = 1;
	for(int i = 1; i <= n; i++){
		long long x;
		char q;
		cin >> x >> q;
		b[sum] += q;
		b[sum + x] -= q;
		sum += x;
	} 
	for(int i = 1; i <= sum; i++){
		qw[i] = qw[i - 1] + b[i];
	}
	
	sum -= 1;
	long long q = sum / 2;
	for(int i = 1; i <= q; i++){
		if(qw[i] != qw[sum]) ans++;
		sum--;
	}
	
	cout << ans << endl;
	return 0;
}



