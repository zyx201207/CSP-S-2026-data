#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n, a[200000];
	string c,C;
	cin >> n;
    for (int i = 1;i <= n; i++){
    	cin >> a[i] >> c[i];
	}
	long long ans = 0,sum = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= a[i]; j++){
			C[sum+j] = c[i];
	    }
	    sum += a[i];
	}
    for (long long i = 1; i <= sum/2; i++){
    	if (C[i] == C[sum-i+1])
    	    ans += 0;
    	else
    	    ans += 1;
	}
	cout << ans;
    return 0;
} 
