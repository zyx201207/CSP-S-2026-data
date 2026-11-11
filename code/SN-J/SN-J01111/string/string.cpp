#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int n, num[N], ans, a[N];
long long sum;
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		num[i] = num[i-1]+a[i];
		sum+=a[i];
	}
	int cl = 1, cr = n;
	long long r = sum;
	for(int l = 1; l <= r; l++, r--){
		if(l > num[cl]) cl++;
		if(r <= num[cr-1]) cr--;
		if(c[cl]!=c[cr]) ans++;
		
	}
	cout << ans;
	return 0;
}
