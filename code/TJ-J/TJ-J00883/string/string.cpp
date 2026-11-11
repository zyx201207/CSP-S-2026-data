#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
long long n;
long long a[N];
char c[N];
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n; i++) cin >> a[i] >> c[i];
	long long l = 1,r = n;
	while(l < r){
		if(a[l] == a[r]){
			if(c[l] == c[r]){
				l++;
				r--;
			} else {
				cnt += a[l];
				l++;
				r--;
			}
		}
		else if(a[l] > a[r]){
			if(c[l] == c[r]){
				a[l] -= a[r];
				r--; 
			} else {
				cnt += a[r];
				a[l] -= a[r];
				r--;
			}
		} else {
			if(c[l] == c[r]){
				a[r] -= a[l];
				l++;
			} else {
				cnt += a[l];
				a[r] -= a[l];
				l++;
			}
		}
		//cout << cnt;
	}
	cout << cnt;
	return 0;
}
/*
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/
