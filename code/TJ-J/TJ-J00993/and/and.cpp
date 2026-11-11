#include<bits/stdc++.h>
using namespace std;

long long n, m, a[100005], an;

bool p(long long a, long long b){
	if(a >= b) return 1;
	return 0;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a+1, a+n+1, p);
	an = a[1];
	
	for(int i = 2; i <= m; i++){
		an = an & a[i];
	}
	
	cout << an;
	
	return 0;
}
