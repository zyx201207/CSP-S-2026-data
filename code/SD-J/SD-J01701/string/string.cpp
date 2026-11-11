#include <bits/stdc++.h>
using namespace std;

int n, a[200003], a1[200003], t, t1;
long long sum = -1, sum1;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s, s1;
	cin >> n;
	for(int i = 0; i < n; i++){
		char q;
		cin >> a[i] >> q;
		s += q;
		s1 = q + s1;
		a1[n-i-1] = a[i];
		sum += a[i];
	}
	 sum /= 2;
	for(long long i = 0; i < sum; ){
		if(sum - i < min(a[t], a1[t])){
			if(s[t] != s1[t1])
				sum1 += sum / 2 - i;
			break;
		}
		else if(a[t] > a1[t1]){
			a[t] -= a1[t1];
			if(s[t] != s1[t1])
				sum1 += a1[t1];
			i += a1[t1];
			t1++;
		}
		else{
			a1[t1] -= a[t];
			if(s[t] != s1[t1])
				sum1 += a[t];
			i += a[t];
			t++;
		}
	}
	cout << sum1;
 	return 0;
}

