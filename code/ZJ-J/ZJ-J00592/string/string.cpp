#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int a[MAXN];
char c[MAXN];

int n;

int main(){
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios :: sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++ i){
		cin >> a[i] >> c[i];
	}
	
	long long left, right;
	left = 1;
	right = n;
	
	long long ans;
	ans = 0;
	
	while(left <= right){
		if(a[left] > a[right]){
			if(c[left] != c[right]){
				ans += 1LL * a[right];
			}
			a[left] -= a[right];
			right --;
		}else if(a[left] < a[right]){
			if(c[left] != c[right]){
				ans += 1LL * a[left];
			}
			a[right] -= a[left];
			left ++;
		}else{
			if(c[left] != c[right]){
				ans += 1LL * a[left];
			}
			left ++;
			right --;
		}
	}
	
	cout << ans;
	
	return 0;
}
