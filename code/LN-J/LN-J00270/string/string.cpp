#include<bits/stdc++.h>
using namespace std;

long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	long long ans = 0;
	long long l = 1,r = n;
	while(l < r){
		if(a[l] < a[r]){
			if(c[l] != c[r]){
				ans += a[l];
			}
			a[r] -= a[l];
			a[l] = 0;
			l++;
		}
		if(a[l] == a[r]){
			if(c[l] != c[r]){
				ans += a[r];
			}
			a[r] = 0;
			a[l] = 0;
			l++;
			r--;
		}
		if(a[l] > a[r]){
			if(c[l] != c[r]){
				ans += a[r];
			}
			a[l] -= a[r];
			a[r] = 0;
			r--;
		}
	}
	cout << ans;
}
