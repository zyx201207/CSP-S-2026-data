#include<bits/stdc++.h>
using namespace std;
long long n, m, a[200001], mx = INT_MIN; 
bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    for(int i = n; i >= n - m + 1; i --){
    	long long k = a[i]; 
    	for(int j = i - 1; j >= i - m + 1; j --){
		    k = k & a[j];
		} 
		mx = max(mx, k);
		if(mx >= a[i - m]) break;
	} 
	cout << mx;
	return 0;
} 
